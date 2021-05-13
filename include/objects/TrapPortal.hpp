#pragma once

#include <include/objects/IPortal.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class TrapPortal : public IPortal {
 public:
  TrapPortal();

  void Interract(PlayerCharacter& /*player*/) const override;
};