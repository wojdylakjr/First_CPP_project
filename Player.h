#pragma once
#include <iostream>

class Player{
    public:
    Player();
    int choosePosition() const; //return position to player's move
    int getNumberOfPlayer() const;


    private:
    static int _number; // variable to set ID number to each player
    int _numberOfPlayer; //ID number
};