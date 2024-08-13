#include "player.h"

Player::Player(uint8_t player_number, uint32_t player_color) {
  this->player_number = player_number;
  this->player_color = player_color;
  victory_amount = 0;
}