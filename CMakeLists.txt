cmake_minimum_required(VERSION 3.15)
project(escape_game LANGUAGES CXX)

include_directories(.)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(third_party)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

set(SOURCES main.cpp)

add_executable(room_escape ${SOURCES})
target_link_libraries(room_escape libs)

###########################################
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Tests ${PROJECT_SOURCE_DIR}/tests/tests.cpp)
target_link_libraries(Tests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Tests libs)

add_test(UnitTests ${PROJECT_SOURCE_DIR}/UnitTests)
enable_testing()
