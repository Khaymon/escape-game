#pragma once

#include "IDoor.hpp"
#include "IPortal.hpp"
#include "IChest.hpp"

class IAbstractFactory {
 public:
  virtual IPortal* CreatePortal() const = 0;
  virtual IDoor* CreateDoor() const = 0;
  virtual IChest* CreateChest() const = 0;
};