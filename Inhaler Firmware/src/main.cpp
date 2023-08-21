#include <Arduino.h>
#include <ArduinoOTA.h>
#include "network/network.h"
#include "device_config.h"
#include "sensor/battery.h"
#include "sensor/mpu6050.h"

void setup() {
  Serial.begin(115200);
  net.begin();
}

void loop() {

}
