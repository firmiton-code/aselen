#include "mpu6050.h"

MPU6050Class *mpu_instances;

MPU6050Class::MPU6050Class(){
  mpu_instances = this;
}

void MPU6050Class::begin(){
  if(!sensor.begin()){
    debug(MPU_TAG, "MPU not connected!");
  } else{
    debug(MPU_TAG, "MPU connected!");
  }
}

String MPU6050Class::position(){
  return "OK";
}

MPU6050Class gyro;