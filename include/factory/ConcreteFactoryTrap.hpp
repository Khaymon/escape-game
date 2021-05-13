#pragma once

#include <include/factory/IAbstractFactory.hpp>
#include <include/objects/TrapChest.hpp>
#include <include/objects/TrapDoor.hpp>
#include <include/objects/TrapPortal.hpp>

class ConcreteFactoryTrap : public IAbstractFactory {
 public:
  TrapPortal* CreatePortal() const override;

  TrapDoor* CreateDoor() const override;

  TrapChest* CreateChest() const override;
};