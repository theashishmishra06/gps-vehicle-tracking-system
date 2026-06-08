#include <TinyGPS++.h>

TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);
  Serial.println("GPS Tracker Started");
}

void loop() {
  Serial.println("Waiting for GPS Data...");
  delay(2000);
}
