#pragma once

#include "IAbstractFactory.hpp"
#include "TrapDoor.hpp"
#include "TrapPortal.hpp"
#include "TrapChest.hpp"

class ConcreteFactoryTrap : public IAbstractFactory {
 public:
  TrapPortal* CreatePortal() const override {
    return new TrapPortal();
  }

  TrapDoor* CreateDoor() const override {
    return new TrapDoor();
  }

  TrapChest* CreateChest() const override {
    return new TrapChest();
  }
};