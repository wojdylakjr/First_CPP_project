#include "Mancala.h"

Mancala::Mancala (){
}


int Mancala::getAmount() const{
    return _currentAmount;
}


void Mancala::setAmount(int newAmount){
    _currentAmount = newAmount;
}

Mancala& Mancala::operator++(){
    ++_currentAmount;
    return *this;
}

void Mancala::addToMancala(int value){
    _currentAmount += value;
}