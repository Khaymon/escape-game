cmake_minimum_required(VERSION 3.15)
project(escape_game LANGUAGES CXX)

include_directories(.)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(third_party)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

configure_file(
  ${PROJECT_SOURCE_DIR}/configure.h.in
  ${PROJECT_SOURCE_DIR}/include/configure.h
  @ONLY
)

set(SOURCES main.cpp)

add_executable(room_escape ${SOURCES})
target_link_libraries(room_escape libs)

install (
  DIRECTORY ${CMAKE_SOURCE_DIR}/levels
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING
  PATTERN "*.json"
)

install(
  TARGETS room_escape libs
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/static
)

###########################################

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Tests ${PROJECT_SOURCE_DIR}/tests/tests.cpp)
target_link_libraries(Tests ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Tests libs)

add_test(Tests ${PROJECT_SOURCE_DIR}/tests/factory/factory_tests.cpp)
add_test(Tests ${PROJECT_SOURCE_DIR}/tests/levels/levels_tests.cpp)
enable_testing()