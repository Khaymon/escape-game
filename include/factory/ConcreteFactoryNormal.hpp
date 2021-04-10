#pragma once

#include <include/factory/IAbstractFactory.hpp>
#include <include/objects/NormalChest.hpp>
#include <include/objects/NormalDoor.hpp>
#include <include/objects/NormalPortal.hpp>

class ConcreteFactoryNormal : public IAbstractFactory {
 public:
  NormalPortal* CreatePortal() const override;

  NormalDoor* CreateDoor() const override;

  NormalChest* CreateChest() const override;
};