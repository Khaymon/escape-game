#pragma once

#include "IAbstractFactory.hpp"
#include "NormalChest.hpp"
#include "NormalDoor.hpp"
#include "NormalPortal.hpp"

class ConcreteFactoryNormal : public IAbstractFactory {
 public:
  NormalPortal* CreatePortal() const override { return new NormalPortal(); }

  NormalDoor* CreateDoor() const override { return new NormalDoor(); }

  NormalChest* CreateChest() const override { return new NormalChest(); }
};