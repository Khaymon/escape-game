#include <include/Coordinates.hpp>

Coordinates::Coordinates() : x(0), y(0) {}

Coordinates::Coordinates(int x, int y) : x(x), y(y) {}

Coordinates::Coordinates(const Coordinates& coordinates) {
  x = coordinates.x;
  y = coordinates.y;
}

Coordinates Coordinates::operator=(const Coordinates& coordinates) {
  x = coordinates.x;
  y = coordinates.y;

  return *this;
}

bool Coordinates::operator==(const Coordinates& coordinates) const {
  return (x == coordinates.x) && (y == coordinates.y);
}

Coordinates Coordinates::operator+(const Coordinates& coordinates) const {
  return Coordinates(x + coordinates.x, y + coordinates.y);
}