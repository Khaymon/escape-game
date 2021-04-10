file(GLOB_RECURSE LIBS_SRC "*.cpp")
message(STATUS "Compiling libraries")
add_library(libs SHARED ${LIBS_SRC})

target_link_libraries(libs nlohmann_json::nlohmann_json)