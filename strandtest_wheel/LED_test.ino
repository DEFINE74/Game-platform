#include "LED_test.h"
void VerticalTest(Player player1, Player player2) {
    for (int x = 13; x <= 24; x++) {
      for (int y = 1; y <= 18; y++) {
        SetPixelVertical(VERTICAL, player2, x, y);
      }
    }
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
void HorizontalTogether(Player player1, Player player2) {
  for (int x = 1; x <= 36; x++) {
    for (int y = 1; y <= 12; y++) {
      yield();
      SetPixelHorizontalTogether(HORIZONTAL_TOGETHER, player1, x, y);
    }
  }
  strip.clear();
}

void VerticalTogether(Player player1, Player player2) {
  for (int x = 1; x <= 24; x++) {
    for (int y = 1; y <= 18; y++) {
      yield();
      SetPixelVerticalTogether(VERTICAL_TOGETHER, player1, x, y);
      }
  }
    strip.clear();
}