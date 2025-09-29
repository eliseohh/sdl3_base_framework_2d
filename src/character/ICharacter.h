#pragma once
#include <iostream>

class ICharacter {
public:
    virtual void move(float x, float y) = 0;
    virtual void attack() = 0;
    virtual void run(float x, float y) = 0;
    virtual ~ICharacter() {}
};
