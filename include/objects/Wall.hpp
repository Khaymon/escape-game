#pragma once

#include <include/Coordinates.hpp>
#include <include/objects/IObject.hpp>

class Wall : public IObject {
 public:
  Wall();
  Wall(Coordinates&& coordinates);

  void Interract(PlayerCharacter& /*player*/) const override;
};