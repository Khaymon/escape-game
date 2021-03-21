#pragma once

#include "IPortal.hpp"
#include "ObjectsData.hpp"

class NormalPortal : public IPortal {
 public:
  NormalPortal() : IPortal(NORMAL_PORTAL_ID) {}

  void Render() const override {
    // TODO: Implement
  }

  void Interract() const override {
    // TODO: Implement
  }
};