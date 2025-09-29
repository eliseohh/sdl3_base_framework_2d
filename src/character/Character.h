#pragma once
#include <iostream>
#include "ICharacter.h"
#include "status/ElementOrientation.h"
#include "renderable/Renderable.h"

namespace character
{
  class Character : public ICharacter, public renderable::Renderable
  {
  public:
    Character(const char *file, SDL_Renderer *renderer);

    void move(float x, float y) override;
    void run(float x, float y) override;
    void attack() override;
    ~Character() override;

  private:
    float positionX = 0.0f;
    float positionY = 0.0f;
    status::ElementOrientation orientation = status::ElementOrientation::DOWN;
    const char *spriteFile = nullptr;
  };
}