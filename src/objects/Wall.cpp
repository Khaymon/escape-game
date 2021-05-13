#include <include/objects/ObjectsData.hpp>
#include <include/objects/Wall.hpp>

Wall::Wall() : Wall(Coordinates(0, 0)) {}
Wall::Wall(const Coordinates coordinates)
    : IObject(WALL_ID, coordinates, WALL_CHAR, WALL_COLOR) {}

void Wall::Interract(PlayerCharacter& player) const {
  // Nothing to do with wall
}
