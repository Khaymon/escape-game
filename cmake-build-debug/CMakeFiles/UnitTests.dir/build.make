# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/145/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/145/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/khaymon/escape_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/khaymon/escape_game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UnitTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UnitTests.dir/flags.make

CMakeFiles/UnitTests.dir/tests/tests.cpp.o: CMakeFiles/UnitTests.dir/flags.make
CMakeFiles/UnitTests.dir/tests/tests.cpp.o: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/khaymon/escape_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UnitTests.dir/tests/tests.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTests.dir/tests/tests.cpp.o -c /home/khaymon/escape_game/tests/tests.cpp

CMakeFiles/UnitTests.dir/tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTests.dir/tests/tests.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/khaymon/escape_game/tests/tests.cpp > CMakeFiles/UnitTests.dir/tests/tests.cpp.i

CMakeFiles/UnitTests.dir/tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTests.dir/tests/tests.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/khaymon/escape_game/tests/tests.cpp -o CMakeFiles/UnitTests.dir/tests/tests.cpp.s

# Object files for target UnitTests
UnitTests_OBJECTS = \
"CMakeFiles/UnitTests.dir/tests/tests.cpp.o"

# External object files for target UnitTests
UnitTests_EXTERNAL_OBJECTS =

bin/UnitTests: CMakeFiles/UnitTests.dir/tests/tests.cpp.o
bin/UnitTests: CMakeFiles/UnitTests.dir/build.make
bin/UnitTests: /usr/local/lib/libgtest.a
bin/UnitTests: CMakeFiles/UnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/khaymon/escape_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/UnitTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnitTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UnitTests.dir/build: bin/UnitTests

.PHONY : CMakeFiles/UnitTests.dir/build

CMakeFiles/UnitTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UnitTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UnitTests.dir/clean

CMakeFiles/UnitTests.dir/depend:
	cd /home/khaymon/escape_game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/khaymon/escape_game /home/khaymon/escape_game /home/khaymon/escape_game/cmake-build-debug /home/khaymon/escape_game/cmake-build-debug /home/khaymon/escape_game/cmake-build-debug/CMakeFiles/UnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UnitTests.dir/depend
