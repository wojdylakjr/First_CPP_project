#include "Logic.h"

void Logic::play() {
  while (continueGame()) {
    _board.showBoard();
    move(_player1.choosePosition(), _player1);

    if (continueGame()) { 
      _board.showBoard();
      move(_player2.choosePosition(), _player2);
    }
  }
  std::cout << "End of the game!" << std::endl;
  endOfGame();
  _board.showBoard();
}



void Logic::move(int position, const Player &player) {
  int currentAmountInHole = _board.getAmountInHole(position - 1, player);

  if (currentAmountInHole == 0) {
    std::cout << "You can't take rocks from empty hole, make your move again!"
              << std::endl;
    move(player.choosePosition(), player);
  } else {
    _board.setAmountInHole(position - 1, player, 0);
    _currentPlayer = player.getNumberOfPlayer(); //seting variable to know which player is making move
    cyclicAdd(position, currentAmountInHole, player);
  }
}



int Logic::increaseAmount(int startIndex, int amount, const Player &player) {
  int currentRocks = amount;

  if (player.getNumberOfPlayer() == 1) {
    int i = 0;
    //for player 1 loop is going from left to right
    //startIndex is number entered by the player, so the real index is startIndex - 1, but we start ading from  next index which is startIndex
    for (i = startIndex; i < amount + startIndex && i < SIZE; i++) {
      _board.incrementAmountinHole(i, player);
      currentRocks--;
    }

    if (currentRocks == 0 && _board.getAmountInHole(i - 1, player) == 1 &&
        player.getNumberOfPlayer() == _currentPlayer) {
      lastHoleRule(i - 1, player);
    }

  } else {
    int i = 0;
    //for player 2 loop is going from right to left
    //startIndex is number entered by the player, so the real index is startIndex - 1, but we start ading from next index which is startIndex -2 
    for (i = startIndex - 2; i > startIndex - amount - 2 && i >= 0; i--) {
      _board.incrementAmountinHole(i, player);
      currentRocks--;
    }

    if (currentRocks == 0 && _board.getAmountInHole(i + 1, player) == 1 &&
        player.getNumberOfPlayer() == _currentPlayer) { 
      lastHoleRule(i + 1, player);
    }
  }

  return currentRocks;
}



void Logic::cyclicAdd(int startIndex, int amount, const Player &player) {

  int currentRocks = increaseAmount(startIndex, amount, player); //adding to next holes untill the own arrays ends or the amount of current rocks is 0

  if (currentRocks == 1 &&
      player.getNumberOfPlayer() ==
          _currentPlayer) { // it means that after going through whole array, there is only one rock, so the move ends in mancala
    currentRocks = _board.incrementMancala(currentRocks, player);
    _board.showBoard();
    if (continueGame()) { //need to check and if it is possible player makes another move
      move(player.choosePosition(), player);
    }
  }

  if (currentRocks > 1 && player.getNumberOfPlayer() == _currentPlayer) { 
    currentRocks = _board.incrementMancala(currentRocks, player); 
  }

  if (currentRocks > 0) { //after adding to one player array and mancala, we starting adding to opponent array
    if (player.getNumberOfPlayer() == 1) {
      cyclicAdd(SIZE + 1, currentRocks,
                _player2); // starting adding tho hole with board index: SIZE
    } else {
      cyclicAdd(0, currentRocks,
                _player1); // starting adding tho hole with board index 1
    }
  }
}



bool Logic::continueGame() {

  if (isArrayEmpty(_board.getArray(_player1)) ||
      isArrayEmpty(_board.getArray(_player2))) {

    return false;
  }
  return true;
}



void Logic::lastHoleRule(int index, const Player &player) {
  int value = 0;

  if (player.getNumberOfPlayer() == 1 &&
      _board.getAmountInHole(index, _player2) != 0) {
    _board.setAmountInHole(index, player, 0); 
    value = _board.getAmountInHole(index, _player2); //get amount in opposite index in opponent array
    _board.setAmountInHole(index, _player2, 0); 
    _board.addToMancala(value + 1, player); // add value + 1 from own hole to own mancala
  } 
  else if (player.getNumberOfPlayer() == 2 &&
     _board.getAmountInHole(index, _player1) != 0) { 
    _board.setAmountInHole(index, player, 0);
    value = _board.getAmountInHole(index, _player1);
    _board.setAmountInHole(index, _player1, 0);
    _board.addToMancala(value + 1, player);
  }
}



bool Logic::isArrayEmpty(Hole *arr) const {
  for (int i = 0; i < SIZE; i++) {
    if (arr[i].getAmount() != 0) {

      return false;
    }
  }
  return true;
}



void Logic::endOfGame() {
  if (isArrayEmpty(_board.getArray(_player1))) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
      sum += _board.getAmountInHole(i, _player2);
      _board.setAmountInHole(i, _player2, 0); 
    }
    _board.addToMancala(sum, _player2);
  }

  else {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
      sum += _board.getAmountInHole(i, _player1);
      _board.setAmountInHole(i, _player1, 0);
    }
    _board.addToMancala(sum, _player1);
  }

  if (_board.getMancala(_player1) > _board.getMancala(_player2)) {
    std::cout << "Player 1 won the game!" << std::endl;
  } else if (_board.getMancala(_player1) < _board.getMancala(_player2)) {
    std::cout << "Player 2 won the game!" << std::endl;
  } else {
    std::cout << "Game ends with draw!" << std::endl;
  }
}
