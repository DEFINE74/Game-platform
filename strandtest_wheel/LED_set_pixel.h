#ifndef LED_SET_PIXEL_H
#define LED_SET_PIXEL_H

enum Orientation {
  VERTICAL,
  HORIZONTAL,
  VERTICAL_TOGETHER,
  HORIZONTAL_TOGETHER,
  INVALID_ARGUMENT
};

void SetPixel(uint16_t& led_index, Player player);

void SetPixelVertical(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD);
void SetPixelHorizontal(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD);

void SetPixelVerticalTogether(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD);
void SetPixelHorizontalTogether(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD);

bool CheckCoordinate(Orientation orientation, Player player, const uint8_t X_COORD, const uint8_t Y_COORD);

#endif