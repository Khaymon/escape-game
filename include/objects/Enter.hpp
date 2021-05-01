#pragma once

#include <include/objects/IChest.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class Enter : public IObject {
 public:
  Enter();
  Enter(const Coordinates& /*coordinates*/);

  void Interract(PlayerCharacter& /*player*/) const override;
};