#pragma once

#include <include/objects/IChest.hpp>
#include <include/objects/IDoor.hpp>
#include <include/objects/IPortal.hpp>

class IAbstractFactory {
 public:
  virtual IPortal* CreatePortal() const = 0;
  virtual IDoor* CreateDoor() const = 0;
  virtual IChest* CreateChest() const = 0;
};