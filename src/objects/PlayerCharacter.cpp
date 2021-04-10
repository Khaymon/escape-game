#include <include/objects/PlayerCharacter.hpp>

PlayerCharacter::PlayerCharacter() : coordinates_(0, 0) {}

PlayerCharacter::PlayerCharacter(Coordinates&& coordinates)
    : coordinates_(coordinates) {}

const uint32_t PlayerCharacter::GetId() const { return id_; }

const char PlayerCharacter::GetSprite() const { return sprite_; }

const uint32_t PlayerCharacter::GetColor() const { return color_; }

const Coordinates PlayerCharacter::GetCoordinates() const {
  return coordinates_;
}

void PlayerCharacter::SetCoordinates(const Coordinates new_coordinates) {
  coordinates_ = new_coordinates;
}