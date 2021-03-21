#pragma once

#include <cinttypes>

class IPortal {
 public:
  IPortal(const uint32_t object_id) : id(object_id), x_(0), y_(0) {}
  virtual void Render() const = 0;
  virtual void Interract() const  = 0;

 public:
  const uint32_t id;

 protected:
  int x_;
  int y_;
};