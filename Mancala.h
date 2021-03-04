#pragma once
#include "Player.h"

class Mancala{
    public:
    Mancala();
    int getAmount() const;
    void setAmount(int newAmount);
    void addToMancala(int value);

    Mancala& operator++(); //overloaded preincremtation operator, increase amount of stones in hole 
   
    private:
    int _currentAmount; //number of current stones in mancala
};