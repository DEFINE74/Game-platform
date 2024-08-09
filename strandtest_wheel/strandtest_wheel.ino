#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN D1

#define LED_AMOUNT 432

//colors
#define RED    strip.Color(255, 0, 0)
#define GREEN  strip.Color(0, 255, 0)
#define BLUE   strip.Color(0, 0, 255)
#define YELLOW strip.Color(255, 255, 0)
#define ORANGE strip.Color(255, 165, 0)
#define WHITE strip.Color(255,255,255)

#define SALAD_GREEN strip.Color(117, 250, 141)
#define PURPLE strip.Color(238, 138, 248)



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

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_AMOUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(10);
  strip.show(); // Initialize all pixels to 'off'
}

Orientation SetOrientation(const uint8_t ORIENTATION_CODE) {
  if (ORIENTATION_CODE == 0) return VERTICAL;
  else if (ORIENTATION_CODE == 1) return HORIZONTAL;
  else if (ORIENTATION_CODE == 2) return VERTICAL_TOGETHER;
  else if (ORIENTATION_CODE == 3) return HORIZONTAL_TOGETHER;
  else return INVALID_ARGUMENT;
}

bool CheckCoordinate(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  switch(orientation) {
  case VERTICAL:
    if (player.player_number == 1 || player.player_number == 2) return (X_COORD >= 0 && X_COORD <= 12) && (Y_COORD >= 0 && Y_COORD <= 18);
    else return false;
  case HORIZONTAL:
    if (player.player_number == 1 || player.player_number == 2) return (X_COORD >= 0 && X_COORD <= 18) && (Y_COORD >= 0 && Y_COORD <= 12);
    else return false;
  case VERTICAL_TOGETHER:
    return (X_COORD >= 0 && X_COORD <= 24) && (Y_COORD >= 0 && Y_COORD <= 18);
  case HORIZONTAL_TOGETHER:
    return (X_COORD >= 0 && X_COORD <= 18) && (Y_COORD >= 0 && Y_COORD <= 24);
  default: 
    return false;
  }
}

void SetPixel(int& led_index, Player player) {
  strip.setPixelColor(led_index, player.player_color);
  strip.show();
}
void SetPixelVertical(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;
  //int led_index = 18 * X_COORD - 18 + Y_COORD - 1
  
  int led_index;
  if (player.player_number == 1) led_index = 18 * X_COORD - 18 + Y_COORD - 1;
  else if (player.player_number == 2) led_index = (18 * X_COORD - 18 + Y_COORD - 1) + 216; //led_index = 18 * (12 - X_COORD) + (18 - Y_COORD) + 216; //led_index = (13 + 13 - Y_COORD) * 18 - 18 * X_COORD - 1; 

  SetPixel(led_index, player);
}
void SetPixelHorizontal(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  //if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;
  int led_index;

  if (player.player_number == 1) led_index = (13 - Y_COORD) * 18 - 19 + X_COORD;
  else if (player.player_number == 2) led_index = 216 + (18 - X_COORD) + 18 * Y_COORD - 18;
  
  SetPixel(led_index, player);
}

void SetPixelHorizontalTogether(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;

  int led_index = 18 * Y_COORD - 18 + X_COORD - 1;

  SetPixel(led_index, player);  
}
void SetPixelVerticalTogether(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;

  int led_index = 18 * X_COORD - 18 + Y_COORD - 1;

  SetPixel(led_index, player);
}

void SetPixelNavigation(const uint8_t ORIENTATION_CODE, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  Orientation game_orientation = SetOrientation(ORIENTATION_CODE);

  switch (game_orientation) {
  case VERTICAL:
    SetPixelVertical(game_orientation, player, X_COORD, Y_COORD);
    break;
  case HORIZONTAL:
    SetPixelHorizontal(game_orientation, player, X_COORD, Y_COORD);
    break;
  case VERTICAL_TOGETHER:
    SetPixelVerticalTogether(game_orientation, player, X_COORD, Y_COORD);
    break;
  case HORIZONTAL_TOGETHER:
    SetPixelHorizontalTogether(game_orientation, player, X_COORD, Y_COORD);
    break;
  default:
    break;
  }
  
}

#define DEBUG
#ifdef DEBUG

  void VerticalTest(Player player1, Player player2) {
    /*
    for (int x = 13; x <= 24; x++) {
      for (int y = 1; y <= 18; y++) {
        SetPixelVertical(VERTICAL, player2, x, y);
      }
    }*/
    for (int y = 1; y <= 18; y++) {
      for (int x = 1; x <= 24; x++) {
        yield();
        SetPixelNavigation(VERTICAL, player1, x, y);
        SetPixelNavigation(VERTICAL, player2, x, y);
      }
    }
  }
  
  void HorizontalTest(Player player1, Player player2) {
    for (int y = 1; y <= 36; y++) {
      for (int x = 1; x <= 18; x++) {
        yield();
        SetPixelHorizontal(HORIZONTAL, player1, x, y);
        SetPixelHorizontal(HORIZONTAL, player2, x, y);
      }
    }
  }
  
#endif

void loop() {
  Player player1(1, SALAD_GREEN); // PLAYER 1 - RED
  Player player2(2, PURPLE); //PLAYER 2 - BLUE

#ifdef DEBUG
  //VerticalTest(player1, player2);
  HorizontalTest(player1, player2);
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
