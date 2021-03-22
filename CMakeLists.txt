cmake_minimum_required(VERSION 3.14)
project(escape_game LANGUAGES CXX)


include_directories(.)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

set(SOURCES src/main.cpp)

add_executable(room_escape ${SOURCES})

###########################################
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(UnitTests ${PROJECT_SOURCE_DIR}/tests/tests.cpp)
target_link_libraries(UnitTests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_test(UnitTests bin/UnitTests)
