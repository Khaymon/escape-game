#pragma once

#include "IChest.hpp"
#include "ObjectsData.hpp"

class NormalChest : public IChest {
 public:
  NormalChest() : IChest(NORMAL_CHEST_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};