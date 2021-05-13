#include <wait.h>

#include <csignal>
#include <ctime>
#include <include/Drawer.hpp>
#include <include/Game.hpp>
#include <iostream>

Game::Game() : current_level_(1) { Drawer::Initialize(); }

void Game::Start() { GameLoop(); }

void Game::GameLoop() {
  int key_pressed = 0;

  while (true) {
    Render();
    key_pressed = toupper(getchar());
    if (key_pressed == 'Q') {
      break;
    } else if (key_pressed == 'W') {
      current_level_.Move(Coordinates(0, -1));
    } else if (key_pressed == 'S') {
      current_level_.Move(Coordinates(0, 1));
    } else if (key_pressed == 'A') {
      current_level_.Move(Coordinates(-1, 0));
    } else if (key_pressed == 'D') {
      current_level_.Move(Coordinates(1, 0));
    }
  }

  Drawer::Finalize();
}

void Game::Render() { current_level_.Render(); }