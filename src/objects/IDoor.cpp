#pragma once

#include <include/objects/IDoor.hpp>
#include <include/objects/ObjectsData.hpp>
#include <utility>

IDoor::IDoor(const uint32_t object_id)
    : IObject(object_id, Coordinates(0, 0), DOOR_CHAR, DOOR_COLOR) {}
IDoor::IDoor(const uint32_t object_id, Coordinates&& coordinates)
    : IObject(object_id, std::move(coordinates), DOOR_CHAR, DOOR_COLOR) {}