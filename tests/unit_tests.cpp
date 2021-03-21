#include <source/IAbstractFactory.hpp>
#include <source/ConcreteFactoryFake.hpp>
#include <source/ConcreteFactoryTrap.hpp>
#include <source/ConcreteFactoryNormal.hpp>
#include <source/ObjectsData.hpp>

#include <gtest/gtest.h>

IChest* CreateChest(IAbstractFactory *factory) {
  IChest *chest = factory->CreateChest();
  return chest;
}

IDoor* CreateDoor(IAbstractFactory *factory) {
  IDoor *door = factory->CreateDoor();
  return door;
}

IPortal* CreatePortal(IAbstractFactory *factory) {
  IPortal *portal = factory->CreatePortal();
  return portal;
}

TEST(UnitTests, CreateTrap) {
  IAbstractFactory *factory;
  factory = new ConcreteFactoryTrap;

  ASSERT_EQ(CreateChest(factory)->id, TRAP_CHEST_ID);
  ASSERT_EQ(CreateDoor(factory)->id, TRAP_DOOR_ID);
  ASSERT_EQ(CreatePortal(factory)->id, TRAP_PORTAL_ID);
}

TEST(UnitTests, CreateFake) {
  IAbstractFactory *factory;
  factory = new ConcreteFactoryFake;

  ASSERT_EQ(CreateChest(factory)->id, FAKE_CHEST_ID);
  ASSERT_EQ(CreateDoor(factory)->id, FAKE_DOOR_ID);
  ASSERT_EQ(CreatePortal(factory)->id, FAKE_PORTAL_ID);
}

TEST(UnitTests, CreateNormal) {
  IAbstractFactory *factory;
  factory = new ConcreteFactoryNormal;

  ASSERT_EQ(CreateChest(factory)->id, NORMAL_CHEST_ID);
  ASSERT_EQ(CreateDoor(factory)->id, NORMAL_DOOR_ID);
  ASSERT_EQ(CreatePortal(factory)->id, NORMAL_PORTAL_ID);
}