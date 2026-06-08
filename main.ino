#include <TinyGPS++.h>

TinyGPSPlus gps;

HardwareSerial gpsSerial(1);
HardwareSerial gsmSerial(2);

String ownerNumber = "+91XXXXXXXXXX";

double initialLat = 0;
double initialLng = 0;
bool firstLocationCaptured = false;

void sendSMS(String msg)
{
  gsmSerial.println("AT+CMGF=1");
  delay(1000);

  gsmSerial.print("AT+CMGS=\"");
  gsmSerial.print(ownerNumber);
  gsmSerial.println("\"");
  delay(1000);

  gsmSerial.print(msg);
  delay(1000);

  gsmSerial.write(26);
  delay(3000);
}

double calculateDistance(
  double lat1,
  double lon1,
  double lat2,
  double lon2)
{
  double x = lat2 - lat1;
  double y = lon2 - lon1;

  return sqrt(x * x + y * y) * 111000;
}

void setup()
{
  Serial.begin(115200);

  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
  gsmSerial.begin(9600, SERIAL_8N1, 26, 27);

  Serial.println("Vehicle Tracking System Started");

  delay(5000);

  gsmSerial.println("AT");
  delay(1000);
}

void loop()
{
  while (gpsSerial.available())
  {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated())
  {
    double lat = gps.location.lat();
    double lng = gps.location.lng();

    String mapsLink =
      "https://maps.google.com/?q=" +
      String(lat, 6) +
      "," +
      String(lng, 6);

    Serial.println("--------------------------------");
    Serial.println("Latitude : " + String(lat, 6));
    Serial.println("Longitude: " + String(lng, 6));
    Serial.println(mapsLink);

    if (!firstLocationCaptured)
    {
      initialLat = lat;
      initialLng = lng;
      firstLocationCaptured = true;

      sendSMS(
        "Vehicle Tracking Activated\n" +
        mapsLink);
    }

    double distance =
      calculateDistance(
        initialLat,
        initialLng,
        lat,
        lng);

    if (distance > 25)
    {
      sendSMS(
        "ALERT!\nUnauthorized Vehicle Movement Detected.\n" +
        mapsLink);

      initialLat = lat;
      initialLng = lng;
    }

    delay(10000);
  }
}
