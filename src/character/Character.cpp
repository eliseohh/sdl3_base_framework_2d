#include "Character.h"
#include <SDL3/SDL.h>
#include "renderable/Renderable.h"

namespace character {
  Character::Character(const char *file, SDL_Renderer *renderer) : renderable::Renderable(renderer, file), spriteFile(file) {}

  void Character::move(float x, float y) {
    positionX += x;
    positionY += y;
  }

  void Character::run(float x, float y) {
    positionX += 2 * x;
    positionY += 2 * y;
  }

  void Character::attack() {
  }

  Character::~Character() {
  }
}
