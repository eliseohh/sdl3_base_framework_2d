#pragma once

#include <SDL3/SDL.h>
#include "constants/FurnitureType.h"

namespace world
{
  class IFurniture
  {
  public:
    virtual const char *getName() const = 0;
    virtual void setName(const char *name) = 0;
    virtual const char *getDescription() const = 0;
    virtual void setDescription(const char *description) = 0;
    virtual const SDL_Rect &getPosition() const = 0;
    virtual bool isInteractable() const = 0;
    virtual void setInteractable(bool interactable) = 0;
    virtual void interact() = 0;
    virtual constants::FurnitureType getType() const = 0;
    virtual ~IFurniture() {}
  };
}