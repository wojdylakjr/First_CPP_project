/* Class to describe board on which the game is played. Each player has got array of 6 holes and his own mancala (base). */
#pragma once
#include <iostream>
#include"Hole.h"
#include"Player.h"
#include"Mancala.h"
#define SIZE 6


class Board{
    public:
    Board();
    void showBoard() const;
    int getAmountInHole(int position, const Player& player) const;
    void setAmountInHole(int position, const Player& player, int newAmount);
    void incrementAmountinHole(int index, const Player& player);
    void setMancala(int value, const Player& player);
    int getMancala(const Player& player) const;
    int incrementMancala(int counter, const Player& player); //return amount of available for player stones decreased of 1 stone, which is in mancala
    int addToMancala( int value, const Player& player); //return current amount od stones in mancala 
    Hole* getArray(const Player& player);
    
    private:
    Hole _player1Array[6];
    Hole _player2Array[6];
    Mancala _mancala1;
    Mancala _mancala2;

};