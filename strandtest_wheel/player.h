#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
  uint8_t player_number;
  uint16_t victory_amount;
  uint32_t player_color;

  Player(uint8_t player_number, uint32_t player_color);
};
#endif