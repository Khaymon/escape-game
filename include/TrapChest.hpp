#pragma once

#include "IChest.hpp"
#include "ObjectsData.hpp"

class TrapChest : public IChest {
 public:
  TrapChest() : IChest(TRAP_CHEST_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};