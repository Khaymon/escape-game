#pragma once

#include "IPortal.hpp"
#include "ObjectsData.hpp"

class TrapPortal : public IPortal {
 public:
  TrapPortal() : IPortal(TRAP_PORTAL_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};