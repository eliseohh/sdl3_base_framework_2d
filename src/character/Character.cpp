#include "Character.h"
#include <SDL3/SDL.h>
#include "renderable/Renderable.h"

namespace character
{
  Character::Character(const char *file, SDL_Renderer *renderer,
                       float positionX, float positionY)
      : renderable::Renderable(renderer, file),
        positionX(positionX),
        positionY(positionY),
        spriteFile(file) {}
  void Character::move(float x, float y)
  {
    this->positionX += x;
    this->positionY += y;
  }

  void Character::setBaseSpeed(status::SpeedStatus speedStatus)
  {
    this->speedStatus = speedStatus;
    switch (speedStatus)
    {
    case status::SpeedStatus::NORMAL:
      this->baseSpeed = 80.0f;
      break;
    case status::SpeedStatus::RUNNING:
      this->baseSpeed = 160.0f;
      break;
    case status::SpeedStatus::CROUCHING:
      this->baseSpeed = 40.0f;
      break;
    default:
      this->baseSpeed = 80.0f;
      break;
    }
  }

  status::SpeedStatus Character::getSpeedStatus() const
  {
    return this->speedStatus;
  }

  float Character::getSpeed() const
  {
    return this->baseSpeed;
  }

  bool Character::isMoving() const
  {
    return this->moving;
  }

  void Character::setMoving(bool moving)
  {
    this->moving = moving;
  }

  void Character::attack()
  {
  }

  void Character::setPosition(float x, float y)
  {
    this->positionX = x;
    this->positionY = y;
  }

  void Character::getPosition(float &x, float &y) const
  {
    x = this->positionX;
    y = this->positionY;
  }

  void Character::setOrientation(status::ElementOrientation orientation)
  {
    this->orientation = orientation;
  }

  status::ElementOrientation Character::getOrientation() const
  {
    return this->orientation;
  }

  Character::~Character()
  {
  }
}
