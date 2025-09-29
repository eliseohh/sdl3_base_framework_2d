#pragma once
#include <SDL3/SDL.h>
#include "IRenderable.h"

namespace renderable
{
  class Renderable : public IRenderable
  {
  public:
    Renderable(SDL_Renderer *renderer, const char *file);
    SDL_Texture *renderTexture() override;

  private:
    SDL_Texture *texture;
  };
}