#include "Player.h"
#include "Board.h"
int Player::_number = 1;

Player::Player() { _numberOfPlayer = _number++; }

int Player::choosePosition() const {
  int position = 0;
  std::cout << "Player " << getNumberOfPlayer() << " chooses position: ";
  std::cin >> position;
  while (position < 0 || position > SIZE) {
    std::cout << "Enter number in range 0 - "<< SIZE << std::endl;
    std::cin >> position;
  }

  return position;
}

int Player::getNumberOfPlayer() const { return _numberOfPlayer; }
