#include "lcd.h"

LCDClass *lcd_instances;

LCDClass::LCDClass(void){
    lcd_instances = this;
}

void LCDClass::init_tft(){
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_WHITE);

    mainBg.createSprite(240, 240);
    mainBg.setSwapBytes(true);

    bgSprite.createSprite(240, 240);
    bgSprite.setSwapBytes(true);
}

void LCDClass::show_logo(){    
    mainBg.fillSprite(TFT_WHITE);
    bgSprite.fillSprite(TFT_WHITE);
    // bgSprite.pushImage(1, 1, 238, 238, _org_logo);
    bgSprite.pushToSprite(&mainBg, 0, 0);
    mainBg.pushSprite(0, 0);

    delay(1500);
}

void LCDClass::show_device_logo(){
    mainBg.fillSprite(TFT_WHITE);
    bgSprite.fillSprite(TFT_WHITE);
    // bgSprite.pushImage(1, 1, 238, 238, device_logo);
    bgSprite.pushToSprite(&mainBg, 0, 0);
    mainBg.pushSprite(0, 0);
}

void LCDClass::update_time(String time, String date){
    mainBg.fillSprite(TFT_WHITE);
    bgSprite.fillSprite(TFT_WHITE);
    // bgSprite.pushImage(1, 1, 238, 238, home_screen);
    bgSprite.setTextDatum(TR_DATUM);
    bgSprite.setTextColor(TFT_BLACK);
    bgSprite.drawString(time, 205, 40, 7);
    bgSprite.drawString(date, 200, 105, 4);
    // bgSprite.pushRotated(&mainBg, _rotate_angle);
    mainBg.pushSprite(0, 0);
}

void LCDClass::moveTo(Menu_screen_t screen_name, int x_pos, int y_pos, uint16_t rotate_angle){
    mainBg.fillSprite(TFT_WHITE);
    // switch(screen_name) {        
    //     case HOME_SCREEN:
    //         bgSprite.pushImage(x_pos+1, y_pos+1, 238, 238, home_screen);
    //         bgSprite.pushRotated(&mainBg, rotate_angle);
    //         break;
    //     default:
    //         bgSprite.pushImage(x_pos+1, y_pos+1, 238, 238, home_screen);
    //         bgSprite.pushRotated(&mainBg, rotate_angle);
    //         break;
    // }
    mainBg.pushSprite(0, 0);
}

LCDClass lcd;