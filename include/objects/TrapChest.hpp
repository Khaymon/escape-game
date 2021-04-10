#pragma once

#include <include/objects/IChest.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class TrapChest : public IChest {
 public:
  TrapChest();

  void Interract(PlayerCharacter& /*player*/) const override;
};