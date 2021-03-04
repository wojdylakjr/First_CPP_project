/*Class where the all magic happens :)*/
#pragma once
#include <iostream>
#include"Player.h"
#include"Board.h"

class Logic{
    public:
    void play(); //method to start game, manages players' moves and checks end of game
    
    void move(int position, const Player& player); //method makes the player's move from position (first argument)
    
    int increaseAmount(int startIndex, int amount, const Player& player);//method as argument takes startIndex from which starts increasing amount in holes untill variable amount = 0 or index is more than 6, returns current available for player amount of rocks
   
    void cyclicAdd(int startIndex, int amount, const Player& player);//method manages, what to do when the rocks should land in opponent's array of holes
    
    bool continueGame(); //checks if in tha array of holes is not empty, if it is it means end of game
    
    void lastHoleRule(int index,const Player& player); //method manages the rule, when the last rock lands in empty hole in player's array of holes
    
    bool isArrayEmpty(Hole* arr) const; //method iterete to check if the array is empty
    
    void endOfGame(); //method manages the rule of end of game



    private:
    Player _player1;
    Player _player2;
    Board _board;
    int _currentPlayer; //variable to set which player is making move
};
