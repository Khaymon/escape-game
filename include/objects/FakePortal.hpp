#pragma once

#include <include/objects/IPortal.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class FakePortal : public IPortal {
 public:
  FakePortal();

  void Interract(PlayerCharacter& /*player*/) const override;
};