#include <Adafruit_NeoPixel.h>


#include "player.h"
#include "LED_set_pixel.h"
#include "LED_test.h"

#define PIN D1
#define LED_AMOUNT 432
#define LCD

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_AMOUNT, PIN, NEO_GRB + NEO_KHZ800); // LED

#ifdef LCD
#define _LCD_TYPE 1  // для работы с I2C дисплеями
#include <LCD_1602_RUS_ALL.h>
#endif

LCD_1602_RUS lcd(0x27, 16, 2); //OLED

void setup() {
  #ifdef LCD
  Wire.begin(D3, D4);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  Player player1;
  Player player2;
  #endif
}


void loop() {
  
}

/*void rainbowCycle(uint8_t wait) {
uint16_t i, j;

for (j = 0; j < 256 * 5; j++) {
for (i = 0; i < strip.numPixels(); i++) {
strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
}
strip.show();
delay(wait);
}
}
uint32_t Wheel(byte WheelPos) {
WheelPos = 255 - WheelPos;
if (WheelPos < 85) {
return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
}
if (WheelPos < 170) {
WheelPos -= 85;
return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
}
WheelPos -= 170;
return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}*/