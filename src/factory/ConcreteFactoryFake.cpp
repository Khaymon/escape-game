#include <include/factory/ConcreteFactoryFake.hpp>

FakePortal* ConcreteFactoryFake::CreatePortal() const {
  return new FakePortal();
}

FakeDoor* ConcreteFactoryFake::CreateDoor() const { return new FakeDoor(); }

FakeChest* ConcreteFactoryFake::CreateChest() const { return new FakeChest(); }