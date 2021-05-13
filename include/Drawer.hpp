#pragma once

#include <include/draw.h>

#include <include/Coordinates.hpp>
#include <include/objects/IObject.hpp>
#include <include/objects/PlayerCharacter.hpp>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class Drawer {
 public:
  static const int upper_bar_height = 1;
  static const int lower_bar_height = 1;
  static const int bar_width = 50;

  Drawer() = delete;

  static void Initialize() {
    clrscr();
    DisableInput();
  }

  static void DrawMap(const std::map<Coordinates, IObject*>& objects) {
    for (auto& object : objects) {
      DrawObject(object.second);
    }
  }

  static void DrawObject(const IObject* object) {
    Draw(object->GetCoordinates(), object->GetSprite(), object->GetColor());
  }

  static void DrawPlayer(const PlayerCharacter& player) {
    Draw(player.GetCoordinates(), player.GetSprite(), player.GetColor());
  }

  static void Draw(const Coordinates& coordinates, const char sprite,
                   const uint32_t color) {
    gotoxy(coordinates.x, coordinates.y + Drawer::upper_bar_height);

    textcolor(color);
    std::cout << sprite;

    gotoxy(1, 1);
  }

  static void DrawUpperBar(const uint32_t color, const std::string& text,
                           const int position) {
    gotoxy(1, 1);
    clreol();
    if (position == 1) {
      DrawText(color, text, Coordinates(1, 1));
    } else if (position == 2) {
      DrawText(color, text, Coordinates(bar_width - text.size(), 1));
    } else {
      throw std::invalid_argument("Position argument must be 1 or 2");
    }
  }

  static void DrawText(const uint32_t color, const std::string& text,
                       const Coordinates position) {
    gotoxy(position.x, position.y);
    textcolor(color);
    std::cout << text;

    gotoxy(1, 1);
  }

  static void DrawStats(const uint32_t coins, const uint32_t health) {}

  static void DrawMessage(const std::string& message) {}

  static void ClearCell(const Coordinates coordinates) {
    gotoxy(coordinates.x, coordinates.y + Drawer::upper_bar_height);
    std::cout << " ";
    gotoxy(1, 1);
  }

  static std::stringstream InputNumber(const Coordinates coordinates) {
    EnableInput();
    gotoxy(1, Drawer::upper_bar_height + coordinates.y + 1);
    std::stringstream ss;
    std::string s;
    std::cin >> s;
    ss << s;

    DisableInput();
    clreol();

    return ss;
  }

  static void Finalize() {
    clrscr();
    exit(EnableInput());  // set default terminal settings
  }

 private:
  static void DisableInput() {
    if (WEXITSTATUS(system(
            "stty cbreak -echo stop u")) ||  // do not show input characters
        WEXITSTATUS(system("stty raw"))) {
      fprintf(stderr, "Failed setting up the screen, is 'stty' missing?\n");
      return exit(1);
    }
  }

  static int EnableInput() { return WEXITSTATUS(system("stty sane")); }

 private:
  static Coordinates shift_;
};