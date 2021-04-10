#pragma once

#include <cinttypes>
#include <include/objects/IObject.hpp>

class IDoor : public IObject {
 public:
  IDoor(const uint32_t object_id);
  IDoor(const uint32_t object_id, Coordinates&& coordinates);
};