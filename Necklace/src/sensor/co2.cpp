#include "co2.h"

Co2Class *co2_instances;

Co2Class::Co2Class(){
  co2_instances = this;
}

bool Co2Class::begin(){
  Wire.begin();
  if (scd.begin() == false){
    return false;
  }

  return true;
}

bool Co2Class::read(){
  if(scd.readMeasurement()){
    _co2 = scd.getCO2();
    _temperature = scd.getTemperature();
    _humidity = scd.getHumidity();

    return true;
  }

  return false;
}

int Co2Class::co2(){
  return _co2;
}

float Co2Class::temperature(){
  return _temperature;
}

float Co2Class::humidity(){
  return _humidity;
}

Co2Class co2;