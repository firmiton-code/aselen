#include "battery.h"

BatteryClass *battery_instances;

BatteryClass::BatteryClass(){
  battery_instances = this;
}

void BatteryClass::begin(){
  pinMode(_pin, INPUT);
}

int BatteryClass::get_percentage(){
  float voltage = (analogRead(_pin) / 1023) * 3.3;
  if(voltage < 2.8){
    return 0;
  }

  int percentage = map(voltage, 2.8, 3.3, 0, 100);
  return percentage;
}

float BatteryClass::get_voltage(){
  float voltage = (analogRead(_pin) / 1023.0) * 3.3;
  return voltage;
}

BatteryClass battery;