#include <include/Player.hpp>
#include <include/objects/ObjectsData.hpp>

Player::Player() : health_(0), coins_(0) {}

Player::Player(int health, int coins) : health_(health_), coins_(coins) {}

const int Player::GetCoins() const { return coins_; }

const int Player::GetHealth() const { return health_; }