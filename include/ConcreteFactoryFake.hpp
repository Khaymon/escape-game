#pragma once

#include "FakeChest.hpp"
#include "FakeDoor.hpp"
#include "FakePortal.hpp"
#include "IAbstractFactory.hpp"

class ConcreteFactoryFake : public IAbstractFactory {
 public:
  FakePortal* CreatePortal() const override { return new FakePortal(); }

  FakeDoor* CreateDoor() const override { return new FakeDoor(); }

  FakeChest* CreateChest() const override { return new FakeChest(); }
};