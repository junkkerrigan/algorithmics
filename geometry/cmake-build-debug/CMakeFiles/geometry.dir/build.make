# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/geometry.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/geometry.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/geometry.dir/flags.make

CMakeFiles/geometry.dir/4.cpp.o: CMakeFiles/geometry.dir/flags.make
CMakeFiles/geometry.dir/4.cpp.o: ../4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/geometry.dir/4.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geometry.dir/4.cpp.o -c /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/4.cpp

CMakeFiles/geometry.dir/4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geometry.dir/4.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/4.cpp > CMakeFiles/geometry.dir/4.cpp.i

CMakeFiles/geometry.dir/4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geometry.dir/4.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/4.cpp -o CMakeFiles/geometry.dir/4.cpp.s

# Object files for target geometry
geometry_OBJECTS = \
"CMakeFiles/geometry.dir/4.cpp.o"

# External object files for target geometry
geometry_EXTERNAL_OBJECTS =

geometry: CMakeFiles/geometry.dir/4.cpp.o
geometry: CMakeFiles/geometry.dir/build.make
geometry: CMakeFiles/geometry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable geometry"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geometry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/geometry.dir/build: geometry

.PHONY : CMakeFiles/geometry.dir/build

CMakeFiles/geometry.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/geometry.dir/cmake_clean.cmake
.PHONY : CMakeFiles/geometry.dir/clean

CMakeFiles/geometry.dir/depend:
	cd /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/cmake-build-debug /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/cmake-build-debug /Users/andriipav/junkkerrigan/study/grade-2/algorithmics/geometry/cmake-build-debug/CMakeFiles/geometry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/geometry.dir/depend

