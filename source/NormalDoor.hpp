#pragma once

#include "IDoor.hpp"
#include "ObjectsData.hpp"

class NormalDoor : public IDoor {
 public:

  NormalDoor() : IDoor(NORMAL_DOOR_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};