#include <include/draw.h>

#include <include/Coordinates.hpp>
#include <include/Drawer.hpp>
#include <include/factory/ConcreteFactoryFake.hpp>
#include <include/factory/ConcreteFactoryNormal.hpp>
#include <include/factory/ConcreteFactoryTrap.hpp>
#include <include/factory/IAbstractFactory.hpp>
#include <include/objects/ObjectsData.hpp>
#include <include/objects/PositionPointer.hpp>
#include <include/objects/Wall.hpp>
#include <iostream>
#include <map>

enum State {
  CHOOSING_OBJECT,
  CHOOSING_TYPE,
  CHOOSING_COINS,
  CHOOSING_DAMAGE,
  PLACING
};

enum Object { OBJECT_NOTHING, DOOR, CHEST, PORTAL, WALL, ENTER, EXIT };

enum Type { TYPE_NOTHING, NORMAL, FAKE, TRAP };

struct ObjectDescription {
  Object object = OBJECT_NOTHING;
  Type type = TYPE_NOTHING;
  uint32_t coins = 0;
  uint32_t damage = 0;
};

void DrawChooseObject() {
  Drawer::DrawUpperBar(WHITE, "W - Wall, D - Door, C - Chest, P - Portal", 1);
}

void DrawChooseType() {
  Drawer::DrawUpperBar(YELLOW, "N - Normal, T - Trap, F - Fake", 1);
}

void DrawChooseCoins() {
  Drawer::DrawUpperBar(BLUE, "Enter the number of coins: ", 1);
}

void DrawChooseDamage() { Drawer::DrawUpperBar(CYAN, "Enter the damage: ", 1); }

void DrawPlacing() {
  Drawer::DrawUpperBar(GREEN,
                       "A, W, S, D - For navigation, Space - Place object, R - "
                       "Remove object, Q - Back to object choosing",
                       1);
}

IObject* CreateObject(Coordinates coordinates,
                      ObjectDescription object_descriptions,
                      std::map<Coordinates, IObject*> objects,
                      Coordinates map_size) {
  IAbstractFactory* factory = nullptr;
  if (object_descriptions.type == NORMAL) {
    factory = new ConcreteFactoryNormal;
  } else if (object_descriptions.type == FAKE) {
    factory = new ConcreteFactoryFake;
  } else if (object_descriptions.type == TRAP) {
    factory = new ConcreteFactoryTrap;
  } else {
    throw std::invalid_argument("Inappropriate type");
  }

  IObject* object = nullptr;
  if (object_descriptions.object == DOOR) {
    object = factory->CreateDoor();
  } else if (object_descriptions.object == CHEST) {
    object = factory->CreateChest();
  } else if (object_descriptions.object == PORTAL) {
    object = factory->CreatePortal();
  } else if (object_descriptions.object == WALL) {
    object = new Wall;
  } else {
    throw std::invalid_argument("Inappropriate object");
  }

  object->SetCoordinates(coordinates);
  return object;
}

void MovePointer(PositionPointer* pointer, Coordinates move_to,
                 Coordinates map_size) {
  Coordinates new_coordinates = pointer->GetCoordinates() + move_to;
  if (new_coordinates.x > 1 && new_coordinates.x < map_size.x &&
      new_coordinates.y > 1 && new_coordinates.y < map_size.y) {
    Drawer::ClearCell(pointer->GetCoordinates());
    pointer->SetCoordinates(new_coordinates);
  }
  auto current_coordinates = pointer->GetCoordinates();
}

void RemoveObject(const Coordinates coordinates,
                  std::map<Coordinates, IObject*>& objects) {
  objects.erase(coordinates);
}

void CreateNewLevel() {
  std::string map_name;
  std::cout << "Enter the map name: ";
  std::cin >> map_name;

  Coordinates map_size;
  std::cout << "Enter the map size (x, y): ";
  std::cin >> map_size.x >> map_size.y;

  std::map<Coordinates, IObject*> objects;
  PositionPointer* position_pointer = new PositionPointer(Coordinates(2, 2));
  objects[position_pointer->GetCoordinates()] = position_pointer;

  for (int i = 1; i <= map_size.x; ++i) {
    auto object = new Wall(Coordinates(i, 1));
    objects[object->GetCoordinates()] = object;
    object = new Wall(Coordinates(i, map_size.y));
    objects[object->GetCoordinates()] = object;
  }

  for (int i = 1; i <= map_size.y; ++i) {
    auto object = new Wall(Coordinates(1, i));
    objects[object->GetCoordinates()] = object;
    object = new Wall(Coordinates(map_size.x, i));
    objects[object->GetCoordinates()] = object;
  }

  Drawer::Initialize();

  State state = State::CHOOSING_OBJECT;
  ObjectDescription object_description;

  char current_char = 0;
  uint32_t coins = 0;
  uint32_t damage = 0;

  while (true) {
    Drawer::DrawMap(objects);
    if (state == State::CHOOSING_OBJECT) {
      DrawChooseObject();
      current_char = toupper(getchar());

      state = State::CHOOSING_TYPE;
      if (current_char == 'W') {
        object_description.object = Object::WALL;
        object_description.type = Type::NORMAL;
        state = State::PLACING;
      } else if (current_char == 'D') {
        object_description.object = Object::DOOR;
      } else if (current_char == 'C') {
        object_description.object = Object::CHEST;
      } else if (current_char == 'P') {
        object_description.object = Object::PORTAL;
      } else {
        state = State::CHOOSING_OBJECT;
      }
    } else if (state == State::CHOOSING_TYPE) {
      DrawChooseType();
      current_char = toupper(getchar());

      if (current_char == 'N') {
        object_description.type = Type::NORMAL;
      } else if (current_char == 'F') {
        object_description.type = Type::FAKE;
      } else if (current_char == 'T') {
        object_description.type = Type::TRAP;
      }
      if (object_description.type != Type::TYPE_NOTHING) {
        if (object_description.object == Object::CHEST) {
          state = State::CHOOSING_COINS;
        } else if (object_description.object == Object::PORTAL &&
                   object_description.type == Type::FAKE) {
          state = State::CHOOSING_DAMAGE;
        } else {
          state = State::PLACING;
        }
      }
    } else if (state == State::CHOOSING_COINS) {
      DrawChooseCoins();
      Drawer::InputNumber(map_size) >> coins;
      if (object_description.type == Type::FAKE) {
        state = State::CHOOSING_DAMAGE;
      } else {
        state = State::PLACING;
      }
    } else if (state == State::CHOOSING_DAMAGE) {
      DrawChooseDamage();
      Drawer::InputNumber(map_size) >> coins;
      state = State::PLACING;
    } else if (state == State::PLACING) {
      DrawPlacing();

      while (true) {
        Drawer::DrawMap(objects);
        gotoxy(position_pointer->GetCoordinates().x,
               position_pointer->GetCoordinates().y + Drawer::upper_bar_height);
        current_char = toupper(getchar());

        if (current_char == 'W') {
          MovePointer(position_pointer, Coordinates(0, -1), map_size);
        } else if (current_char == 'S') {
          MovePointer(position_pointer, Coordinates(0, 1), map_size);
        } else if (current_char == 'A') {
          MovePointer(position_pointer, Coordinates(-1, 0), map_size);
        } else if (current_char == 'D') {
          MovePointer(position_pointer, Coordinates(1, 0), map_size);
        } else if (current_char == ' ') {
          auto object = CreateObject(position_pointer->GetCoordinates(),
                                     object_description, objects, map_size);
          objects[object->GetCoordinates()] = object;
        } else if (current_char == 'R') {
          RemoveObject(position_pointer->GetCoordinates(), objects);
        } else if (current_char == 'Q') {
          current_char = 0;
          object_description.object = OBJECT_NOTHING;
          object_description.type = TYPE_NOTHING;
          object_description.coins = 0;
          object_description.damage = 0;
          state = State::CHOOSING_OBJECT;
          break;
        }
      }
    } else {
      throw std::invalid_argument("Invalid state");
    }
    if (current_char == 'Q') {
      break;
    }
  }

  Drawer::Finalize();
}

int main() {
  std::cout << "Create new level or edit existing? (1 - new level, 0 - edit): ";
  int what = 0;
  std::cin >> what;
  if (what == 0) {
    // Not implemented
  } else if (what == 1) {
    CreateNewLevel();
  } else {
    std::cout << "Invalid action\n";
  }
}