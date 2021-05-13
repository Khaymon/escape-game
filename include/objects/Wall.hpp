#pragma once

#include <include/Coordinates.hpp>
#include <include/objects/IObject.hpp>

class Wall : public IObject {
 public:
  Wall();
  Wall(const Coordinates coordinates);

  void Interract(PlayerCharacter& /*player*/) const override;
};