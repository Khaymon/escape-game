#pragma once

#include <include/objects/IDoor.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class TrapDoor : public IDoor {
 public:
  TrapDoor();

  void Interract(PlayerCharacter& /*player*/) const override;
};