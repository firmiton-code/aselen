#ifndef DEVICE_CONFIG_H_
#define DEVICE_CONFIG_H_

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#include "network/network.h"
#include "sensor/battery.h"
#include "sensor/mpu6050.h"

#define debug(x, y)         Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.println(y);
#define debugVal(x, y, z)   Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.print(y); Serial.println(z);

#define DEFAULT_SSID        "R3"
#define DEFAULT_PASS        "01062003"
#define DEFAULT_AP_SSID     "aselene-inhaler"

#endif // DEVICE_CONFIG_H_