#ifndef LCD_H_
#define LCD_H_

#include <Arduino.h>

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#include "../device_config.h"
#include "lcd_asset.h"

#define LCD_TAG "LCD"

typedef enum {
    // Main Menu
    BOOT_SCREEN,
    HOME_SCREEN,
    CO2_SCREEN,
    BREATH_SCREEN,
    BPM_SCREEN
} Menu_screen_t;

#define small_font  4
#define big_font    6
#define number_font 7

class LCDClass {
    private:
        TFT_eSPI tft = TFT_eSPI();
        TFT_eSprite mainBg = TFT_eSprite(&tft);   //full
        TFT_eSprite bgSprite = TFT_eSprite(&tft);   //full

    public:
        LCDClass(void);
        void init_tft(void);
        void show_logo();
        void show_device_logo();
        void update_time(String time, String date);

        void moveTo(Menu_screen_t screen_name, int x_pos, int y_pos, uint16_t rotate_angle);
};

extern LCDClass lcd;

#endif // LCD_H_