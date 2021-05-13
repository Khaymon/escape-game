#include <include/objects/PositionPointer.hpp>

PositionPointer::PositionPointer(const Coordinates coordinates)
    : IObject(POSITION_POINTER_ID, coordinates, POSITION_POINTER_CHAR,
              POSITION_POINTER_COLOR) {}

void PositionPointer::Interract(PlayerCharacter& /*player*/) const {
  // Do nothing
}