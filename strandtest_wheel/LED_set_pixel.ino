#include "LED_set_pixel.h"

void SetPixel(uint16_t& led_index, Player player) {
  strip.setPixelColor(led_index, player.player_color);
  strip.show();
}

//vertical & horizontal FOR 2 PLAYER
void SetPixelVertical(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;
  
  uint16_t led_index;
  if (player.player_number == 1) led_index = 18 * X_COORD - 18 + Y_COORD - 1;
  else if (player.player_number == 2) led_index = (18 * X_COORD - 18 + Y_COORD - 1) + 216;

  SetPixel(led_index, player);
}
void SetPixelHorizontal(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;
  uint16_t led_index;

  if (player.player_number == 1) led_index = (13 - Y_COORD) * 18 - 19 + X_COORD;
  else if (player.player_number == 2) led_index = 216 + (18 - X_COORD) + 18 * Y_COORD - 18;
  
  SetPixel(led_index, player);
}

//vertical & horizontal FOR 1 PLAYER
void SetPixelVerticalTogether(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;

  uint16_t led_index = 18 * X_COORD - 18 + Y_COORD - 1;

  SetPixel(led_index, player);
}
void SetPixelHorizontalTogether(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  if (!CheckCoordinate(orientation, player, X_COORD, Y_COORD)) return;
  uint16_t led_index;

  if(X_COORD > 18) led_index = (12 + Y_COORD) * 18 - (X_COORD - 18);
  else led_index = (13 - Y_COORD) * 18 - 19 + X_COORD;

  SetPixel(led_index, player);  
}


void SetPixelNavigation(Orientation game_orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD) {
  
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
    return (X_COORD >= 0 && X_COORD <= 36) && (Y_COORD >= 0 && Y_COORD <= 12);
  default: 
    return false;
  }
}