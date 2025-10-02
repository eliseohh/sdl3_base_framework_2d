#pragma once

namespace IRoom
{
  class IRoom
  {
  public:
    virtual const char *getName() const = 0;
    virtual void setName(const char *name) = 0;
    virtual void addAdjacentRoom(IRoom *room) = 0;
    virtual IRoom **getAdjacentRooms(int &count) const = 0;
    virtual void moveToPreviousRoom() = 0;
    virtual IRoom *getCurrentRoom() const = 0;
    
    virtual ~IRoom() {}
  };
}