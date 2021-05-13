#pragma once

#include <include/objects/IDoor.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class FakeDoor : public IDoor {
 public:
  FakeDoor();

  void Interract(PlayerCharacter& /*player*/) const override;
};