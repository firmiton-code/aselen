#ifndef CO2_h_
#define CO2_h_

#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_SCD4x_Arduino_Library.h"

class Co2Class{
  private:
    SCD4x scd;

    int _co2;
    float _temperature;
    float _humidity;

  public:
    Co2Class();
    bool begin();
    bool read();
    int co2();
    float temperature();
    float humidity();
};

extern Co2Class co2;

#endif // CO2_h_