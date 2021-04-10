#include <gtest/gtest.h>

#include <include/factory/ConcreteFactoryFake.hpp>
#include <include/factory/ConcreteFactoryNormal.hpp>
#include <include/factory/ConcreteFactoryTrap.hpp>
#include <include/factory/IAbstractFactory.hpp>
#include <include/objects/ObjectsData.hpp>

IChest *CreateChest(IAbstractFactory *factory) {
  IChest *chest = factory->CreateChest();
  return chest;
}

IDoor *CreateDoor(IAbstractFactory *factory) {
  IDoor *door = factory->CreateDoor();
  return door;
}

IPortal *CreatePortal(IAbstractFactory *factory) {
  IPortal *portal = factory->CreatePortal();
  return portal;
}

TEST(FactoryTests, CreateTrap) {
  IAbstractFactory *factory;
  factory = new ConcreteFactoryTrap;

  ASSERT_EQ(CreateChest(factory)->GetId(), TRAP_CHEST_ID);
  ASSERT_EQ(CreateDoor(factory)->GetId(), TRAP_DOOR_ID);
  ASSERT_EQ(CreatePortal(factory)->GetId(), TRAP_PORTAL_ID);
}

TEST(FactoryTests, CreateFake) {
  IAbstractFactory *factory;
  factory = new ConcreteFactoryFake;

  ASSERT_EQ(CreateChest(factory)->GetId(), FAKE_CHEST_ID);
  ASSERT_EQ(CreateDoor(factory)->GetId(), FAKE_DOOR_ID);
  ASSERT_EQ(CreatePortal(factory)->GetId(), FAKE_PORTAL_ID);
}

TEST(FactoryTests, CreateNormal) {
  IAbstractFactory *factory;
  factory = new ConcreteFactoryNormal;

  ASSERT_EQ(CreateChest(factory)->GetId(), NORMAL_CHEST_ID);
  ASSERT_EQ(CreateDoor(factory)->GetId(), NORMAL_DOOR_ID);
  ASSERT_EQ(CreatePortal(factory)->GetId(), NORMAL_PORTAL_ID);
}
