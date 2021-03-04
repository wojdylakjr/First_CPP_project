#pragma once
#include <iostream>
#include "Player.h"


class Hole{
    public:
    int getAmount() const;
    void setAmount(int newAmount);

    Hole& operator++(); //overloaded preincremtation operator, increase amount of stones in hole   
    private:
    int _currentAmount; //number of current stones in hole
};