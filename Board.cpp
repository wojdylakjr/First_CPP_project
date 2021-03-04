#include "Board.h"


Board::Board(){
    for(int i = 0; i < SIZE; i++){
        _player1Array[i].setAmount(4);
        _player2Array[i].setAmount(4);
        _mancala1.setAmount(0);
        _mancala2.setAmount(0);
    }
}



void Board::showBoard() const{
  std::cout << std::endl;
  std::cout << "################## KALAHA ##################" << std::endl;
  std::cout << "#  ___                                ___  #" << std::endl;
  
  std::cout << "# |   |";
  for (int i = 0; i < SIZE; i++) {
    std::cout << " [" << _player2Array[i].getAmount() << "] ";
  }
  std::cout << "|   | #" << std::endl;

  std::cout << "# |   |                              |   | #" << std::endl;
  std::cout << "# | " << _mancala2.getAmount() << " |                              " << "| " << _mancala1.getAmount() << " | #" << std::endl;
  std::cout << "# |   |                              |   | #" << std::endl;
  
  std::cout << "# |___|";
  for (int i = 0; i < SIZE; i++) {
    std::cout << " [" << _player1Array[i].getAmount() << "] ";
  }
  std::cout << "|___| #" << std::endl;

  std::cout << "#                                          #" << std::endl;
  std::cout << "############################################" << std::endl;

}

int Board::getAmountInHole(int position, const Player& player) const{
  if(player.getNumberOfPlayer() == 1){
    return _player1Array[position].getAmount();
  }  
  else{
      return _player2Array[position].getAmount();
  }
}


void Board::setAmountInHole(int position, const Player& player, int newAmount){
      if(player.getNumberOfPlayer() == 1){
    _player1Array[position].setAmount(newAmount);
  }  
  else{
    _player2Array[position].setAmount(newAmount);
  }
}


void Board::incrementAmountinHole(int index,const Player& player) {
    if(player.getNumberOfPlayer() == 1){
    ++_player1Array[index];
  }  
  else{
    ++_player2Array[index];
  }
}


void Board::setMancala(int value, const Player& player){
    if(player.getNumberOfPlayer() == 1){
     _mancala1.setAmount(value);
  }  
  else{
     _mancala2.setAmount(value);
  }
}

int Board::getMancala(const Player& player) const{
        if(player.getNumberOfPlayer() == 1){
     return _mancala1.getAmount();
  }  
  else{
    return _mancala2.getAmount();
  }
}


int Board::incrementMancala(int counter, const Player& player){
  if(player.getNumberOfPlayer() == 1){
    ++_mancala1;
  }  
  else{
    ++_mancala2;
  }
  return --counter; 
}

int Board::addToMancala( int value, const Player& player){
      if(player.getNumberOfPlayer() == 1){
    _mancala1.addToMancala(value);
    return _mancala1.getAmount();
  }  
  else{
    _mancala2.addToMancala(value);
    return _mancala2.getAmount();
  }

}

Hole* Board::getArray(const Player& player){
    if(player.getNumberOfPlayer() == 1){
    return _player1Array;
  }  
  else{
    return _player2Array;
  }
}