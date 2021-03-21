#pragma once

#include "IDoor.hpp"
#include "ObjectsData.hpp"

class TrapDoor : public IDoor {
 public:
  TrapDoor() : IDoor(TRAP_DOOR_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};