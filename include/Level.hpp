#pragma once

#include <cinttypes>
#include <include/Drawer.hpp>
#include <include/factory/IAbstractFactory.hpp>
#include <include/objects/IObject.hpp>
#include <include/objects/PlayerCharacter.hpp>
#include <map>
#include <nlohmann/json.hpp>
#include <string>

class LevelTester;

class Level {
 public:
  Level(uint32_t /*level_number*/);

  Level(const nlohmann::json& /*level*/);

  Level(Level&) = delete;

  Level(Level&&) = default;

  Coordinates GetMapSize();

  void Render() const;

  void Move(const Coordinates coordinates);

 private:
  void LoadLevel();

  void InitializeLevel(const nlohmann::json& /*level_data*/);

  void LoadObjectsFromKey(const nlohmann::json& /*objects*/,
                          const std::string& /*key*/,
                          IAbstractFactory* /*factory*/);

  void InitializeObjects(const nlohmann::json& /*objects*/,
                         IAbstractFactory* /*factory*/);

  void InitializeWalls(const nlohmann::json& /*objects*/);

  void InitializePlayerCharacter(const Coordinates /*coordinates*/);

 private:
  friend LevelTester;
  // size of the map (x - width, y - height)
  Coordinates size_;
  std::map<Coordinates, IObject*> objects_;
  PlayerCharacter player_charecter_;
  uint32_t level_number_;
};

class LevelTester {
 public:
  LevelTester(const nlohmann::json& /*level_data*/);

  const std::map<Coordinates, IObject*>& GetObjects() const;

  Level level;
};