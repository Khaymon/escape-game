#include <include/objects/ObjectsData.hpp>
#include <include/objects/Wall.hpp>
#include <utility>

Wall::Wall() : IObject(WALL_ID, Coordinates(0, 0), WALL_CHAR, WALL_COLOR) {}
Wall::Wall(Coordinates&& coordinates)
    : IObject(WALL_ID, std::move(coordinates), WALL_CHAR, WALL_COLOR) {}

void Wall::Interract(PlayerCharacter& player) const {
  // Nothing to do with wall
}
