#pragma once

#include <include/objects/IChest.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class Exit : public IObject {
 public:
  Exit();
  Exit(const Coordinates& /*coordinates*/);

  void Interract(PlayerCharacter& /*player*/) const override;
};