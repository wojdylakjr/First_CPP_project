#include "Player.h"
#include "Board.h"
int Player::_number = 1;

Player::Player() { _numberOfPlayer = _number++; }

int Player::choosePosition() const {
  int position = 0;
  std::cout << "Player " << getNumberOfPlayer() << " chooses position: ";
  std::cin >> position;
  while (std::cin.fail() || (position <= 0 || position > SIZE)) {
    std::cout << "Enter number in range 1 - " << SIZE << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin >> position;
  }

  return position;
}

int Player::getNumberOfPlayer() const { return _numberOfPlayer; }
