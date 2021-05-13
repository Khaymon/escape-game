#pragma once

#include <include/objects/IPortal.hpp>
#include <include/objects/ObjectsData.hpp>
#include <utility>

IPortal::IPortal(const uint32_t object_id)
    : IObject(object_id, Coordinates(0, 0), PORTAL_CHAR, PORTAL_COLOR) {}
IPortal::IPortal(const uint32_t object_id, Coordinates&& coordinates)
    : IObject(object_id, std::move(coordinates), PORTAL_CHAR, PORTAL_COLOR) {}