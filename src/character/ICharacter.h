#pragma once
#include <iostream>
#include "constants/ElementOrientation.h"
#include "constants/SpeedStatus.h"

class ICharacter
{
public:
    virtual void move(float x, float y) = 0;
    virtual void attack() = 0;
    virtual void setBaseSpeed(constants::SpeedStatus speedStatus) = 0;
    virtual constants::SpeedStatus getSpeedStatus() const = 0;
    virtual float getSpeed() const = 0;
    virtual bool isMoving() const = 0;
    virtual void setMoving(bool moving) = 0;
    virtual void getPosition(float &x, float &y) const = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setOrientation(constants::ElementOrientation orientation) = 0;
    virtual constants::ElementOrientation getOrientation() const = 0;
    virtual ~ICharacter() {}
};
