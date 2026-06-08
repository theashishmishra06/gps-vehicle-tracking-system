# GPS-Based Vehicle Tracking and Anti-Theft System

## Project Overview
Developed a GPS-based vehicle tracking and anti-theft system using ESP32, GPS, and GSM modules. The system enables real-time vehicle tracking, SMS-based alerts, and location sharing through Google Maps links.

## Features
- Real-time vehicle location tracking
- GPS coordinate acquisition using NEO-6M GPS module
- SMS alerts using GSM module
- Google Maps link generation for instant navigation
- Unauthorized vehicle movement detection
- Remote monitoring capability

## Hardware Used
- ESP32 Development Board
- NEO-6M GPS Module
- SIM800L GSM Module
- Power Supply Module

## Software Used
- Arduino IDE
- Embedded C++
- TinyGPS++ Library

## System Architecture

GPS Module → ESP32 → GSM Module → User Mobile

## Working
1. GPS module continuously acquires location coordinates.
2. ESP32 processes latitude and longitude data.
3. GSM module sends SMS alerts containing vehicle location.
4. User receives a Google Maps link for live tracking.
5. If unauthorized movement is detected, an alert SMS is generated automatically.

## Results
- Successfully tracked vehicle location in real time.
- Generated Google Maps links with accurate coordinates.
- Sent SMS alerts during movement events.
- Demonstrated anti-theft monitoring functionality.

## Future Scope
- Mobile application integration
- Cloud-based tracking dashboard
- Geofencing alerts
- Engine immobilization system

## Author
Ashish Mishra  
B.Tech Electronics and Communication Engineering  
National Institute of Technology Silchar
