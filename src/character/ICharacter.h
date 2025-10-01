#pragma once
#include <iostream>
#include "status/ElementOrientation.h"
#include "status/SpeedStatus.h"

class ICharacter
{
public:
    virtual void move(float x, float y) = 0;
    virtual void attack() = 0;
    virtual void setBaseSpeed(status::SpeedStatus speedStatus) = 0;
    virtual status::SpeedStatus getSpeedStatus() const = 0;
    virtual float getSpeed() const = 0;
    virtual bool isMoving() const = 0;
    virtual void setMoving(bool moving) = 0;
    virtual void getPosition(float &x, float &y) const = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setOrientation(status::ElementOrientation orientation) = 0;
    virtual status::ElementOrientation getOrientation() const = 0;
    virtual ~ICharacter() {}
};
