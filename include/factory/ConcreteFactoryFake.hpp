#pragma once

#include <include/factory/IAbstractFactory.hpp>
#include <include/objects/FakeChest.hpp>
#include <include/objects/FakeDoor.hpp>
#include <include/objects/FakePortal.hpp>

class ConcreteFactoryFake : public IAbstractFactory {
 public:
  FakePortal* CreatePortal() const override;

  FakeDoor* CreateDoor() const override;

  FakeChest* CreateChest() const override;
};