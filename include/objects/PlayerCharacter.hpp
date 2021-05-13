#pragma once

#include <cinttypes>
#include <include/Coordinates.hpp>
#include <include/objects/ObjectsData.hpp>

class PlayerCharacter {
 public:
  PlayerCharacter();

  PlayerCharacter(Coordinates&& coordinates);

  const uint32_t GetId() const;

  const char GetSprite() const;

  const uint32_t GetColor() const;

  const Coordinates GetCoordinates() const;

  void SetCoordinates(const Coordinates new_coordinates);

 private:
  const uint32_t id_ = PLAYER_ID;
  const char sprite_ = PLAYER_CHAR;
  const uint32_t color_ = PLAYER_COLOR;
  Coordinates coordinates_;
};