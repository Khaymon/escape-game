#include <include/factory/ConcreteFactoryTrap.hpp>

TrapPortal* ConcreteFactoryTrap::CreatePortal() const {
  return new TrapPortal();
}

TrapDoor* ConcreteFactoryTrap::CreateDoor() const { return new TrapDoor(); }

TrapChest* ConcreteFactoryTrap::CreateChest() const { return new TrapChest(); }