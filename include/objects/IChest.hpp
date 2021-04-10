#pragma once

#include <cinttypes>
#include <include/objects/IObject.hpp>

class IChest : public IObject {
 public:
  IChest(const uint32_t object_id);
  IChest(const uint32_t object_id, Coordinates&& coordinates);
};