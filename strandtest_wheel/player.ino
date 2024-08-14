#include "player.h"

Player::Player() {
  _player_name = "";
  _game_name = "";
  _player_number = 1;
  _player_score = 0;
}
Player::Player(uint8_t _player_number, uint32_t player_color) {
  this->_player_number = _player_number;
  this->player_color = player_color;
  _player_score = 0;
}

void Player::SetGameName(String _game_name) {
  this->_game_name = _game_name;
}
void Player::SetName(String _player_name) {
  this->_player_name = _player_name;
}
void Player::SetScore(uint8_t _player_score ) {
  this->_player_score = _player_score;
}

String Player::GetGameName() {
  return _game_name;
}
String Player::GetName() {
  return _player_name;
}
uint8_t Player::GetScore() {
  return _player_score;
}
uint8_t Player::GetPlayerNumber() {
  return _player_number;
}
void Player::AddScore(uint8_t _player_score) {
  this->_player_score += _player_score;
}





