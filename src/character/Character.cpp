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

  void Character::run(float x, float y)
  {
    this->positionX += 2 * x;
    this->positionY += 2 * y;
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
