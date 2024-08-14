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

uint8_t CalculateScoreIndex(Player player) {
  const uint8_t DISPLAY_LENGTH = 16;
  String score_str = (String)player.GetScore();

  uint8_t index = DISPLAY_LENGTH - score_str.length();

  return index;
}
void PrintNameScore(Player player) {
  const uint8_t DISPLAY_X = CalculateScoreIndex(player);
  const uint8_t DISPLAY_Y = player.GetPlayerNumber() - 1;

  lcd.setCursor(0, DISPLAY_Y);
  lcd.print(player.GetName());
  lcd.setCursor(DISPLAY_X, DISPLAY_Y);
  lcd.print((String)player.GetScore());

}
void setup() {
  Player player1(1, GREEN);
  Player player2(2, BLUE);
  
  #ifdef LCD
  Wire.begin(D3, D4);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  player1.SetName("Саня");
  player1.SetScore(221);

  player2.SetName("Петя");
  player2.SetScore(255);

  PrintNameScore(player1);
  PrintNameScore(player2);

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