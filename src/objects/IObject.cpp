#include <include/objects/IObject.hpp>

IObject::IObject(const uint32_t object_id, Coordinates&& coordinates,
                 char sprite, uint32_t color)
    : id_(object_id),
      coordinates_(coordinates),
      sprite_(sprite),
      color_(color) {}

const uint32_t IObject::GetId() const { return id_; }

const char IObject::GetSprite() const { return sprite_; }

const uint32_t IObject::GetColor() const { return color_; }

Coordinates IObject::GetCoordinates() const { return coordinates_; }

void IObject::SetCoordinates(const Coordinates coordinates) {
  coordinates_ = coordinates;
}