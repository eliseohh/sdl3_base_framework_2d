#include "Furniture.h"
#include <SDL3/SDL.h>

namespace world
{
  Furniture::Furniture(const char *name, const char *description, const SDL_Rect &position,
                       bool interactable, constants::FurnitureType type, SDL_Renderer *renderer, const char *filePath)
      : name(name), description(description), position(position), interactable(interactable), type(type), renderable::Renderable(renderer, filePath) {}

  const char *Furniture::getName() const
  {
    return this->name;
  }

  void Furniture::setName(const char *name) const
  {
    this->name = name;
  }

  const char *Furniture::getDescription() const
  {
    return this->description;
  }

  void Furniture::setDescription(const char *description) const
  {
    this->description = description;
  }

  const SDL_Rect &Furniture::getPosition() const
  {
    return this->position;
  }

  bool Furniture::isInteractable() const
  {
    return this->interactable;
  }

  void Furniture::setInteractable(bool interactable) const
  {
    this->interactable = interactable;
  }

  void Furniture::interact() const
  {
    if (this->interactable)
    {
      SDL_Log("You interacted with the %s.", this->name);
    }
    else
    {
      SDL_Log("The %s is not interactable.", this->name);
    }
  }

}