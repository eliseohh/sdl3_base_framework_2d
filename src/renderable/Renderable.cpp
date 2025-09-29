#include "Renderable.h"
#include <SDL3_Image/SDL_image.h>

namespace renderable
{
  Renderable::Renderable(SDL_Renderer *renderer, const char *filePath) : texture(IMG_LoadTexture(renderer, filePath)) {}

  SDL_Texture *Renderable::renderTexture()
  {
    return texture;
  }
}