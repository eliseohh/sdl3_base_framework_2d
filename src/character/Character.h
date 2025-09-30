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
    Character(const char *file, SDL_Renderer *renderer, float positionX, float positionY);

    void move(float x, float y) override;
    void run(float x, float y) override;
    void attack() override;
    void setPosition(float x, float y) override;
    void getPosition(float &x, float &y) const override;
    void setOrientation(status::ElementOrientation orientation) override;
    status::ElementOrientation getOrientation() const override;
    ~Character() override;

  private:
    float positionX = 0.0f;
    float positionY = 0.0f;
    status::ElementOrientation orientation = status::ElementOrientation::DOWN;
    const char *spriteFile = nullptr;
  };
}