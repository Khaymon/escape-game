#pragma once

#include <include/objects/IDoor.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class NormalDoor : public IDoor {
 public:
  NormalDoor();

  void Interract(PlayerCharacter& /*player*/) const override;
};