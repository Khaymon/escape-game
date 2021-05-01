#pragma once

#include <cinttypes>
#include <include/Coordinates.hpp>
#include <include/objects/PlayerCharacter.hpp>

class IObject {
 public:
  IObject(const uint32_t /*object_id*/, const Coordinates /*coordinates*/,
          char /*sprite*/, uint32_t /*color*/);

  virtual void Interract(PlayerCharacter& /*player*/) const = 0;

  const uint32_t GetId() const;

  const char GetSprite() const;

  const uint32_t GetColor() const;

  Coordinates GetCoordinates() const;

  void SetCoordinates(const Coordinates /*coordinates*/);

  bool operator<(const IObject& /*another*/) const;

 private:
  const char sprite_;
  const uint32_t color_;
  const uint32_t id_;
  Coordinates coordinates_;
};