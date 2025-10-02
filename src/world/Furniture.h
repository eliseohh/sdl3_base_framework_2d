#pragma once

#include <SDL3/SDL.h>
#include "IFurniture.h"
#include "constants/FurnitureType.h"
#include "renderable/Renderable.h"

namespace world
{
  class Furniture : public IFurniture, public renderable::Renderable
  {
  public:
    Furniture(const char *name, const char *description, const SDL_Rect &position,
              bool interactable, constants::FurnitureType type, SDL_Renderer *renderer, const char *filePath);
    const char *getName() const override;
    void setName(const char *name) override;
    const char *getDescription() const override;
    void setDescription(const char *description) override;
    const SDL_Rect &getPosition() const override;
    bool isInteractable() const override;
    void setInteractable(bool interactable) override;
    void interact() override;
    constants::FurnitureType getType() const override;
    ~Furniture() override;

  private:
    char *name;
    char *description;
    SDL_Rect position;
    bool interactable;
    constants::FurnitureType type;
  };

}