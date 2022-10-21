# IoTemp

IoTemp is a simple project that aims to be able to monitor temperature and humidity with IoT devices through a smartphone application

## Hardware (IoT Device)
- ESP8266 (Microcontroller)
- DHT11 (Temperature and Humidity Sensor)
- 16x2 LCD display
- 18650 Battery; BMS; 18650 Charging Module

## IOT Architecture
The DHT11 sensor will capture temperature and humidity, then the ESP8266 will display temperature and humidity data in the display module, while sending data to Firebase Firestore. From firebase, the data will be passed to the end-user device, where the data will be displayed in the android application
![alt text](https://github.com/anthonywsss/iotTemp/blob/main/Images/IoT%20Architecture.png?raw=true)

## Application UI and IoT Devices
Temperature and Humidity Monitoring UI
![alt text](https://github.com/anthonywsss/iotTemp/blob/main/Images/Temperature%20UI.jpg?raw=true)

Setting Alert UI
![alt text](https://github.com/anthonywsss/iotTemp/blob/main/Images/Set%20Alert%20UI.jpg?raw=true)

Arduino Devices
![alt text](https://github.com/anthonywsss/iotTemp/blob/main/Images/Arduino%20Devices.jpg?raw=true)
![alt text](https://github.com/anthonywsss/iotTemp/blob/main/Images/On%20Code%20Arduino.jpg?raw=true)
