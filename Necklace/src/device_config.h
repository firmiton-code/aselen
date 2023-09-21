#ifndef DEVICE_CONFIG_H_
#define DEVICE_CONFIG_H_

#include <Arduino.h>
#include <String.h>
#include "sensor/breath.h"
#include "sensor/co2.h"
#include "display/lcd.h"

#define FIREBASE_USE_PSRAM

#define DEFAULT_SSID        "3DPratical"
#define DEFAULT_PASS        "embeddedpractical"
#define DEFAULT_AP_SSID     "Aselen-Necklace"

#define DEFAULT_URL         "vismate-fef88-default-rtdb.firebaseio.com"
#define DEFAULT_KEY         "lvXzLsvRfQdOoK4BHCfYg9VETtzKjevxkqnLNGdU"

#define DEFAULT_DEVICE_CODE (uint32_t)ESP.getEfuseMac()

#define debug(x, y)         Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.println(y);
#define debugVal(x, y, z)   Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.print(y); Serial.println(z);

#endif // DEVICE_CONFIG_H_