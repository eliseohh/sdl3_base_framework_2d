#pragma once
#include <iostream>
#include "ICharacter.h"
#include "constants/ElementOrientation.h"
#include "constants/SpeedStatus.h"
#include "renderable/Renderable.h"

namespace character
{
  class Character : public ICharacter, public renderable::Renderable
  {
  public:
    Character(const char *file, SDL_Renderer *renderer, float positionX, float positionY);

    void move(float x, float y) override;
    void setBaseSpeed(constants::SpeedStatus speedStatus) override;
    constants::SpeedStatus getSpeedStatus() const override;
    float getSpeed() const override;
    bool isMoving() const override;
    void setMoving(bool moving) override;
    void attack() override;
    void setPosition(float x, float y) override;
    void getPosition(float &x, float &y) const override;
    void setOrientation(constants::ElementOrientation orientation) override;
    constants::ElementOrientation getOrientation() const override;
    ~Character() override;

  private:
    float positionX = 0.0f;
    float positionY = 0.0f;
    float baseSpeed = 80.0f;
    bool moving = false;
    constants::ElementOrientation orientation = constants::ElementOrientation::DOWN;
    constants::SpeedStatus speedStatus = constants::SpeedStatus::NORMAL;
  };
}