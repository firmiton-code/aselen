#ifndef MPU6050_H_
#define MPU6050_H_

#include <Arduino.h>
#include "Adafruit_MPU6050.h"
#include "../device_config.h"

#define MPU_TAG "MPU"

class MPU6050Class {
  private:
    Adafruit_MPU6050 sensor;

  public:
    MPU6050Class();
    void begin();
    String position();
};

extern MPU6050Class gyro;

#endif // MPU6050_H_