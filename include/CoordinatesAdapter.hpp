#pragma once

#include <include/Coordinates.hpp>
#include <nlohmann/json.hpp>

class CoordinatesAdapter {
 public:
  CoordinatesAdapter() = delete;

  static Coordinates GetCoordinates(const nlohmann::json& converting) {
    return Coordinates(converting["x"], converting["y"]);
  }
};