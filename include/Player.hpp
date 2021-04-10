#pragma once

#include <include/Coordinates.hpp>

class Player {
 public:
  Player();

  Player(int health, int coins);

  const int GetCoins() const;

  const int GetHealth() const;

 private:
  int coins_{0};
  int health_;
};