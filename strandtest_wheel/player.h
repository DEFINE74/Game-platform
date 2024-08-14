#ifndef PLAYER_H
#define PLAYER_H

#include <Arduino.h>

class Player {
private:
  String _game_name;
  String _player_name;
  uint8_t _player_score;
  uint8_t _player_number;
public:
  uint32_t player_color;

  Player();
  Player(uint8_t player_number, uint32_t player_color);

void SetGameName(String _game_name);
void SetName(String _player_name);
void SetScore(uint8_t _player_score );

String GetGameName();
String GetName();
uint8_t GetScore();
void AddScore(uint8_t _player_score);

uint8_t GetPlayerNumber();

};
#endif