#include <include/Level.hpp>
#include <include/objects/IObject.hpp>
#include <include/objects/ObjectsData.hpp>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

TEST(LevelsTests, MapSize) {
  auto level_data = R"(
    {
      "size": {"x": 42, "y": 42},
      "walls": [],
      "normal": {
        "door": [],
        "chest": [],
        "portal": []
      },
      "fake": {
        "door": [],
        "chest": [],
        "portal": []
      },
      "trap": {
        "door": [],
        "chest": [],
        "portal": []
      },

      "start": {"x": 15, "y": 15},
      "exit": {"x": 1, "y": 1}
    }
  )"_json;

  Level level(level_data);
  ASSERT_EQ(level.GetMapSize(), Coordinates(42, 42));
}

TEST(LevelTests, ObjectsCount) {
  auto level_data = R"(
    {
      "size": {"x": 42, "y": 42},
      "walls": [
        {"x": [5], "y": [6, 7, 8]}
      ],
      "normal": {
        "door": [
          {"x": 4, "y": 5}
        ],
        "chest": [],
        "portal": []
      },
      "fake": {
        "door": [],
        "chest": [
          {"x": 14, "y": 4}
        ],
        "portal": []
      },
      "trap": {
        "door": [],
        "chest": [],
        "portal": [
          {"x": 5, "y": 18}
        ]
      },

      "start": {"x": 15, "y": 15},
      "exit": {"x": 1, "y": 1}
    }
  )"_json;

  LevelTester level_tester(level_data);

  ASSERT_EQ(level_tester.GetObjects().size(), 3);
}

TEST(LevelTests, AllChests) {
  auto level_data = R"(
    {
      "size": {"x": 42, "y": 42},
      "walls": [
        {"x": [5], "y": [6, 7, 8]}
      ],
      "normal": {
        "door": [],
        "chest": [{"x": 4, "y": 5}],
        "portal": []
      },
      "fake": {
        "door": [],
        "chest": [{"x": 14, "y": 4}],
        "portal": []
      },
      "trap": {
        "door": [],
        "chest": [{"x": 5, "y": 18}],
        "portal": []
      },

      "start": {"x": 15, "y": 15},
      "exit": {"x": 1, "y": 1}
    }
  )"_json;

  LevelTester level_tester(level_data);

  for (auto& object: level_tester.GetObjects()) {
    ASSERT_EQ(object.second->GetId(), NORMAL_CHEST_ID);
  }
}

TEST(LevelTests, AllDoors) {
  auto level_data = R"(
    {
      "size": {"x": 42, "y": 42},
      "walls": [
        {"x": [5], "y": [6, 7, 8]}
      ],
      "normal": {
        "door": [{"x": 4, "y": 5}],
        "chest": [],
        "portal": []
      },
      "fake": {
        "door": [{"x": 14, "y": 4}],
        "chest": [],
        "portal": []
      },
      "trap": {
        "door": [{"x": 5, "y": 18}],
        "chest": [],
        "portal": []
      },

      "start": {"x": 15, "y": 15},
      "exit": {"x": 1, "y": 1}
    }
  )"_json;

  LevelTester level_tester(level_data);

  for (auto& object: level_tester.GetObjects()) {
    ASSERT_EQ(object.second->GetId(), NORMAL_DOOR_ID);
  }
}

TEST(LevelTests, AllPortals) {
  auto level_data = R"(
    {
      "size": {"x": 42, "y": 42},
      "walls": [
        {"x": [5], "y": [6, 7, 8]}
      ],
      "normal": {
        "door": [],
        "chest": [],
        "portal": [{"x": 4, "y": 5}]
      },
      "fake": {
        "door": [],
        "chest": [],
        "portal": [{"x": 14, "y": 4}]
      },
      "trap": {
        "door": [],
        "chest": [],
        "portal": [{"x": 5, "y": 18}]
      },

      "start": {"x": 15, "y": 15},
      "exit": {"x": 1, "y": 1}
    }
  )"_json;

  LevelTester level_tester(level_data);

  for (auto& object: level_tester.GetObjects()) {
    ASSERT_EQ(object.second->GetId(), NORMAL_PORTAL_ID);
  }
}