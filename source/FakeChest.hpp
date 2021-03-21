#pragma once

#include "IChest.hpp"
#include "ObjectsData.hpp"

class FakeChest : public IChest {
 public:

  FakeChest() : IChest(FAKE_CHEST_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};