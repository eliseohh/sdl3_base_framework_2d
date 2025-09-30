#pragma once
#include <iostream>
#include "status/ElementOrientation.h"

class ICharacter
{
public:
    virtual void move(float x, float y) = 0;
    virtual void attack() = 0;
    virtual void run(float x, float y) = 0;
    virtual void getPosition(float &x, float &y) const = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setOrientation(status::ElementOrientation orientation) = 0;
    virtual status::ElementOrientation getOrientation() const = 0;
    virtual ~ICharacter() {}
};
