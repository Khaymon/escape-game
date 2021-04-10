#pragma once

#include <include/draw.h>

#include <include/Coordinates.hpp>
#include <include/objects/IObject.hpp>
#include <include/objects/PlayerCharacter.hpp>
#include <iostream>
#include <string>
#include <vector>

class Drawer {
 public:
  Drawer() = delete;

  static void Initialize(const Coordinates& map_size) { clrscr(); }

  static void DrawMap(const std::vector<IObject*>& objects) {
    for (auto& object : objects) {
      DrawObject(object);
    }
  }

  static void DrawObject(const IObject* object) {
    Draw(object->GetCoordinates(), object->GetSprite(), object->GetColor());
  }

  static void DrawPlayer(const PlayerCharacter& player) {
    Draw(player.GetCoordinates(), player.GetSprite(), player.GetColor());
  }

  static void Draw(const Coordinates& coordinates, char sprite,
                   uint32_t color) {
    gotoxy(coordinates.x, coordinates.y);

    textcolor(color);
    std::cout << sprite;

    gotoxy(1, 1);
  }

  static void DrawStats(const uint32_t coins, const uint32_t health) {}

  static void DrawMessage(const std::string& message) {}

  static void ClearCell(const Coordinates coordinates) {
    gotoxy(coordinates.x, coordinates.y);
    std::cout << " ";
    gotoxy(1, 1);
  }

  static void Finalize() {
    clrscr();
    exit(WEXITSTATUS(system("stty sane")));
  }

 private:
  static Coordinates shift_;
};