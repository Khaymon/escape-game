#pragma once

#include "IDoor.hpp"
#include "ObjectsData.hpp"

class FakeDoor : public IDoor {
 public:

  FakeDoor() : IDoor(FAKE_DOOR_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};