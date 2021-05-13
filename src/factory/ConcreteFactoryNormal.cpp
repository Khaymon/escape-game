#include <include/factory/ConcreteFactoryNormal.hpp>

NormalPortal* ConcreteFactoryNormal::CreatePortal() const {
  return new NormalPortal();
}

NormalDoor* ConcreteFactoryNormal::CreateDoor() const {
  return new NormalDoor();
}

NormalChest* ConcreteFactoryNormal::CreateChest() const {
  return new NormalChest();
}