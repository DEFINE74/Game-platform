#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN D1
#define DEBUG

enum Orientation {
  VERTICAL,
  HORIZONTAL,
  VERTICAL_TOGETHER,
  HORIZONTAL_TOGETHER,
  INVALID_ARGUMENT
};

class Player {
public:
  uint8_t player_number;
  uint32_t player_color;
  Player(uint8_t player_number, uint32_t player_color) {
    this->player_number = player_number;
    this->player_color = player_color;
  }
};

Adafruit_NeoPixel strip = Adafruit_NeoPixel(432, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
}

void SetPixelVertical(Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  
}

void SetPixelHorizontal(Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  
}

Orientation SetOrientation(const uint8_t ORIENTATION_CODE) {
  if (ORIENTATION_CODE == 0) return VERTICAL;
  else if (ORIENTATION_CODE == 1) return HORIZONTAL;
  else if (ORIENTATION_CODE == 2) return VERTICAL_TOGETHER;
  else if (ORIENTATION_CODE == 3) return HORIZONTAL_TOGETHER;
  else return INVALID_ARGUMENT;
}

bool CheckCoordinate(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {

  /*switch(player.player_number) {
    case 1:
      return (X_COORD >= 0 && X_COORD <= 12) && (Y_COORD >= 0 && Y_COORD <= 18);
    case 2:
      return (X_COORD >= 13 && X_COORD <= 24) && (Y_COORD >= 0 && Y_COORD <= 18);
  }*/
  return false;
}

void SetPixelVertical(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;
}
void SetPixel(const uint8_t ORIENTATION_CODE, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
 
  Orientation game_orientation = SetOrientation(ORIENTATION_CODE);
  int led_index = 18 * X_COORD - 18 + Y_COORD - 1;

  switch()
  if (Orientation == VERTICAL) {
    SetPixelVertical(game_orientation, player, X_COORD, Y_COORD);

  }
  
  strip.setPixelColor(led_index, player.player_color);
  strip.show();
}

#ifdef DEBUG
void test(Player& player1, Player& player2) {
  //for player 1
  for(int x = 12; x > 0; x--) {
    SetPixel(0, player1, x, 1);
  }
  for(int y = 18; y > 0; y--) {
    SetPixel(0, player1, 1, y);
  }


}
#endif

void loop() {
  Player player1(1, strip.Color(255, 0, 0)); // PLAYER 1 - RED
  Player player2(2, strip.Color(0, 0, 255)); 

#ifdef DEBUG
  test(player1, player2);
#endif
  
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
