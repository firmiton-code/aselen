#ifndef DEVICE_CONFIG_H_
#define DEVICE_CONFIG_H_

#define debug(x, y)         Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.println(y);
#define debugVal(x, y, z)   Serial.print("[");Serial.print(millis());Serial.print("]"); Serial.print("[");Serial.print(x);Serial.print("] "); Serial.print(y); Serial.println(z);

#define DEFAULT_SSID        "R3"
#define DEFAULT_PASS        "01062003"
#define DEFAULT_AP_SSID     "aselene-inhaler"

#endif // DEVICE_CONFIG_H_