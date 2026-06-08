# GPS-Based Vehicle Tracking and Anti-Theft System

## Overview

An ESP32-based smart vehicle tracking and anti-theft system that provides real-time GPS tracking, SMS alerts, Google Maps navigation links, and unauthorized movement detection.

## Features

- Real-time GPS tracking
- Google Maps link generation
- SMS notifications using GSM
- Anti-theft movement detection
- Remote vehicle monitoring
- Embedded C implementation on ESP32

## Hardware Used

- ESP32 Dev Module
- NEO-6M GPS Module
- SIM800L GSM Module

## Software Used

- Arduino IDE
- Embedded C++
- TinyGPS++

## Working

1. GPS module continuously reads location.
2. ESP32 processes latitude and longitude.
3. Google Maps link is generated automatically.
4. GSM module sends SMS updates.
5. Vehicle movement beyond predefined threshold triggers theft alert.

## Project Architecture

GPS Module → ESP32 → GSM Module → User Mobile

## Results

- Successfully tracked vehicle position.
- Generated accurate Google Maps links.
- Sent SMS alerts during movement events.
- Demonstrated anti-theft monitoring capability.

## Future Improvements

- Geo-fencing
- Mobile App Integration
- Cloud Dashboard
- Engine Immobilizer

## Author

Ashish Mishra

B.Tech Electronics and Communication Engineering

National Institute of Technology Silchar
