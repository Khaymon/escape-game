#pragma once

#include "IPortal.hpp"
#include "ObjectsData.hpp"

class FakePortal : public IPortal {
 public:
  FakePortal() : IPortal(FAKE_PORTAL_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};