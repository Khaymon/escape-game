#pragma once

#include <include/objects/IObject.hpp>

// Class for editing levels
class PositionPointer : public IObject {
 public:
  PositionPointer(const Coordinates /*coordinates*/);

  void Interract(PlayerCharacter& /*player*/) const override;
};