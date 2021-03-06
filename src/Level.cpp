#include <include/configure.h>

#include <fstream>
#include <include/CoordinatesAdapter.hpp>
#include <include/Level.hpp>
#include <include/factory/ConcreteFactoryFake.hpp>
#include <include/factory/ConcreteFactoryNormal.hpp>
#include <include/factory/ConcreteFactoryTrap.hpp>
#include <include/objects/Wall.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

Level::Level(uint32_t level_number) : level_number_(level_number) {
  LoadLevel();
}

Level::Level(const nlohmann::json& level_data) { InitializeLevel(level_data); }

void Level::LoadLevel() {
  std::string all_levels_path(INSTALL_PATH + std::string("/levels/all.json"));
  std::ifstream input_file(all_levels_path);
  nlohmann::json all_levels_data;

  input_file >> all_levels_data;
  input_file.close();

  std::string path_to_level(
      INSTALL_PATH +
      std::string("/levels/" + all_levels_data[0].get<std::string>()));
  std::cout << path_to_level << std::endl;
  input_file.open(path_to_level);
  std::ifstream level_file(path_to_level);

  nlohmann::json level_data;
  level_file >> level_data;
  std::cout << level_data;

  InitializeLevel(level_data);
}

void Level::InitializeLevel(const nlohmann::json& level_data) {
  size_ = Coordinates(level_data["size"]["x"], level_data["size"]["y"]);

  InitializeObjects(level_data["normal"], new ConcreteFactoryNormal());
  InitializeObjects(level_data["fake"], new ConcreteFactoryFake());
  InitializeObjects(level_data["trap"], new ConcreteFactoryTrap());

  InitializeWalls(level_data["walls"]);
  InitializePlayerCharacter(
      CoordinatesAdapter::GetCoordinates(level_data["start"]));
}

Coordinates Level::GetMapSize() { return size_; }

void Level::Render() const {
  Drawer::DrawMap(objects_);
  Drawer::DrawPlayer(player_charecter_);
}

void Level::Move(const Coordinates coordinates) {
  auto new_coordinates = player_charecter_.GetCoordinates() + coordinates;
  bool collides = false;
  for (const auto& object : objects_) {
    if (new_coordinates == object.second->GetCoordinates()) {
      object.second->Interract(player_charecter_);
      collides = true;
      break;
    }
  }
  if (!collides) {
    Drawer::ClearCell(player_charecter_.GetCoordinates());
    player_charecter_.SetCoordinates(player_charecter_.GetCoordinates() +
                                     coordinates);
  }
}

void Level::InitializeObjects(const nlohmann::json& objects,
                              IAbstractFactory* factory) {
  LoadObjectsFromKey(objects, "door", factory);
  LoadObjectsFromKey(objects, "chest", factory);
  LoadObjectsFromKey(objects, "portal", factory);
}

void Level::LoadObjectsFromKey(const nlohmann::json& objects,
                               const std::string& key,
                               IAbstractFactory* factory) {
  for (const auto& object : objects[key]) {
    auto* new_object = factory->CreateDoor();
    new_object->SetCoordinates(CoordinatesAdapter::GetCoordinates(object));
    objects_[new_object->GetCoordinates()] = new_object;
  }
}

void Level::InitializeWalls(const nlohmann::json& objects) {
  for (const auto& block : objects) {
    for (int x = block["x"][0]; x <= block["x"][1]; ++x) {
      for (int y = block["y"][0]; y <= block["y"][1]; ++y) {
        auto object = new Wall(Coordinates(x, y));
        objects_[object->GetCoordinates()] = object;
      }
    }
  }
}

void Level::InitializePlayerCharacter(const Coordinates coordinates) {
  player_charecter_.SetCoordinates(coordinates);
}

LevelTester::LevelTester(const nlohmann::json& level_data)
    : level(level_data) {}

const std::map<Coordinates, IObject*>& LevelTester::GetObjects() const {
  return level.objects_;
}