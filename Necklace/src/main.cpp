#include <Arduino.h>
#include "device_config.h"

// Get microphone data function
void getData(void *param)
{
  while(1){
    int rangelimit = breath.getSensitivity();
    Serial.print(rangelimit * -1);
    Serial.print(" ");
    Serial.print(rangelimit);
    Serial.print(" ");
    Serial.println(breath.raw());
    vTaskDelay(5 / portTICK_PERIOD_MS);
  }
}

void getCO2(void *param){
  while(1){
    if (co2.read()) // readMeasurement will return true when fresh data is available
    {
      Serial.println();

      Serial.print(F("CO2(ppm):"));
      Serial.print(co2.co2());

      Serial.print(F("\tTemperature(C):"));
      Serial.print(co2.temperature(), 1);

      Serial.print(F("\tHumidity(%RH):"));
      Serial.print(co2.humidity(), 1);

      Serial.println();
    }

    vTaskDelay(1 / portTICK_PERIOD_MS);
  }
}

void setup(void) {
  Serial.begin(115200);

  co2.begin();
  breath.begin();
  lcd.init_tft();
  
  ledcSetup(0, 14000, 12);
  ledcAttachPin(26, 0);
  ledcWrite(0, 64);

  ledcWriteTone(0, 4096);
  delay(100);
  ledcWriteTone(0, 0);
  delay(50);
  ledcWriteTone(0, 1024);
  delay(100);
  ledcWriteTone(0, 0);
  delay(50);
  ledcWriteTone(0, 512);
  delay(150);
  ledcWriteTone(0, 0);

  delay(5000);

  // pinMode(27, INPUT_PULLUP);

  xTaskCreate(getData, "Get sensor breath data", 10000, NULL, 4, NULL);         // create get data task
  // xTaskCreate(getCO2, "Get sensor CO2 data", 5000, NULL, 4, NULL);         // create get data task

  vTaskDelete(NULL);
}

void loop() {
    ledcWriteTone(0, 512);
    delay(100);
    ledcWriteTone(0, 0);
    delay(50);
    ledcWriteTone(0, 3072);
    delay(100);
    ledcWriteTone(0, 0);
    delay(50);
    ledcWriteTone(0, 4096);
    delay(150);
    ledcWriteTone(0, 0);

    delay(5000);

    // Binary inversion of colours
    ledcWriteTone(0, 512);
    delay(100);
    ledcWriteTone(0, 0);
    delay(50);
    ledcWriteTone(0, 3072);
    delay(100);
    ledcWriteTone(0, 0);
    delay(50);
    ledcWriteTone(0, 1024);
    delay(150);
    ledcWriteTone(0, 0);
    delay(50);
    ledcWriteTone(0, 4096);
    delay(150);
    ledcWriteTone(0, 0);

    delay(5000);
}
