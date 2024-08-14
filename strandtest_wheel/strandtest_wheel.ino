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
  #endif
  Serial.begin(9600);
  strip.begin();

  strip.setBrightness(10);
  strip.show();

  Wire.begin(D3, D4);

  Player player1(1, GREEN); // PLAYER 1 - RED
  player1.SetName("Володя 25 лет");
  player1.SetScore(10);

  lcd.print(player1.GetName());
  lcd.setCursor(0,1);
  lcd.print("Очков: ");
  lcd.print((String)player1.GetScore());

  delay(2000);

  player1.AddScore(70);
  lcd.clear(); lcd.setCursor(0,0);
  lcd.print(player1.GetName());

  lcd.setCursor(0,1);

  lcd.print("Очков: ");
  lcd.print((String)player1.GetScore());

  delay(2000);
  lcd.clear(); lcd.setCursor(0, 0);

  lcd.print("Вы выбрали игру");
  lcd.setCursor(5,1);
  player1.SetGameName("Нардыы");
  lcd.print((String)player1.GetGameName());
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