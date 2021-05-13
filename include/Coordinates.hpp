#pragma once

struct Coordinates {
  Coordinates();

  Coordinates(int x, int y);

  Coordinates(const Coordinates& /*coordinates*/);

  Coordinates operator=(const Coordinates& /*coordinates*/);

  bool operator==(const Coordinates& /*coordinates*/) const;

  bool operator<(const Coordinates coordinates) const;

  Coordinates operator+(const Coordinates& /*coordinates*/) const;

  int x;
  int y;
};