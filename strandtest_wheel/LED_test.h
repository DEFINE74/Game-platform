#ifndef LED_TEST_H
#define LED_TEST_H

#include "player.h"

#define RED    strip.Color(255, 0, 0)
#define GREEN  strip.Color(0, 255, 0)
#define BLUE   strip.Color(0, 0, 255)
#define YELLOW strip.Color(255, 255, 0)
#define ORANGE strip.Color(255, 165, 0)
#define WHITE strip.Color(255,255,255)

#define SALAD_GREEN strip.Color(117, 250, 141)
#define PURPLE strip.Color(238, 138, 248)

void VerticalTest(Player player1, Player player2);
void HorizontalTest(Player player1, Player player2);
void HorizontalTogether(Player player1, Player player2);
void VerticalTogether(Player player1, Player player2);

#endif