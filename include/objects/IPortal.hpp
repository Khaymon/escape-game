#pragma once

#include <cinttypes>
#include <include/objects/IObject.hpp>

class IPortal : public IObject {
 public:
  IPortal(const uint32_t object_id);
  IPortal(const uint32_t object_id, Coordinates&& coordinates);
};