#include <include/objects/IChest.hpp>
#include <include/objects/ObjectsData.hpp>
#include <utility>

IChest::IChest(const uint32_t object_id)
    : IObject(object_id, Coordinates(0, 0), CHEST_CHAR, CHEST_COLOR) {}
IChest::IChest(const uint32_t object_id, Coordinates&& coordinates)
    : IObject(object_id, std::move(coordinates), CHEST_CHAR, CHEST_COLOR) {}
