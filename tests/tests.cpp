#include <tests/factory/factory_tests.cpp>
#include <tests/levels/levels_tests.cpp>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
