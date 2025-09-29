#pragma once
#include <SDL3/SDL.h>

class IRenderable {
public:
    virtual SDL_Texture* renderTexture() = 0;
    virtual ~IRenderable() = default;
};