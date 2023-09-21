#ifndef Breath_h_
#define Breath_h_

#include <Arduino.h>
#include <driver/i2s.h>

#define I2S_PORT I2S_NUM_0
#define bufferLen 64

class BreathClass{
  private:
    uint8_t I2S_WS = 5;
    uint8_t I2S_SD = 19;
    uint8_t I2S_SCK = 18;

    int16_t _sBuffer[bufferLen];
    
    uint32_t _micSensitivity = 150;
    uint32_t _micTolerance = 400;
  
  public:
    BreathClass();
    void begin();
    int raw();
    int read();
    int getSensitivity();
};

extern BreathClass breath;

#endif // Breath_h_