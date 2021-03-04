#include "Hole.h"

int Hole::getAmount() const{
    return _currentAmount;
}


void Hole::setAmount(int newAmount){
    _currentAmount = newAmount;
}

Hole& Hole::operator++(){
    ++_currentAmount;
    return *this;
}

