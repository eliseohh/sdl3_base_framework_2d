#pragma once
#include <iostream>
#include "ICharacter.h"
#include "status/ElementOrientation.h"
#include "status/SpeedStatus.h"
#include "renderable/Renderable.h"

namespace character
{
  class Character : public ICharacter, public renderable::Renderable
  {
  public:
    Character(const char *file, SDL_Renderer *renderer, float positionX, float positionY);

    void move(float x, float y) override;
    void setBaseSpeed(status::SpeedStatus speedStatus) override;
    status::SpeedStatus getSpeedStatus() const override;
    float getSpeed() const override;
    bool isMoving() const override;
    void setMoving(bool moving) override;
    void attack() override;
    void setPosition(float x, float y) override;
    void getPosition(float &x, float &y) const override;
    void setOrientation(status::ElementOrientation orientation) override;
    status::ElementOrientation getOrientation() const override;
    ~Character() override;

  private:
    float positionX = 0.0f;
    float positionY = 0.0f;
    float baseSpeed = 80.0f;
    bool moving = false;
    status::ElementOrientation orientation = status::ElementOrientation::DOWN;
    status::SpeedStatus speedStatus = status::SpeedStatus::NORMAL;
    const char *spriteFile = nullptr;
  };
}