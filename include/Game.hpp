#include <include/Level.hpp>
#include <include/Player.hpp>
#include <include/Tester.hpp>
#include <vector>

class Game {
 public:
  Game();

  Game(Game&&) = delete;
  Game(Game&) = delete;

  void Start();

  friend class Tester;

 private:
  void GameLoop();

  void Render();

 private:
  bool is_playing_{true};
  Player player_;
  Level current_level_;
};