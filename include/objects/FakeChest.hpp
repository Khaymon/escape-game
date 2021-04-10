#pragma once

#include <include/objects/IChest.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class FakeChest : public IChest {
 public:
  FakeChest();

  void Interract(PlayerCharacter& /*player*/) const override;
};