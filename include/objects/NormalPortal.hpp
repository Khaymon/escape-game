#pragma once

#include <include/objects/IPortal.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PlayerCharacter.hpp>

class NormalPortal : public IPortal {
 public:
  NormalPortal();

  void Interract(PlayerCharacter& /*player*/) const override;
};