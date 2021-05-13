#pragma once

#include <include/objects/IChest.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class NormalChest : public IChest {
 public:
  NormalChest();

  void Interract(PlayerCharacter& /*player*/) const override;
};