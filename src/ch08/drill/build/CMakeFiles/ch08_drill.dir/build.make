# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build

# Include any dependencies generated for this target.
include CMakeFiles/ch08_drill.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ch08_drill.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ch08_drill.dir/flags.make

CMakeFiles/ch08_drill.dir/src/my.cpp.o: CMakeFiles/ch08_drill.dir/flags.make
CMakeFiles/ch08_drill.dir/src/my.cpp.o: ../src/my.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ch08_drill.dir/src/my.cpp.o"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch08_drill.dir/src/my.cpp.o -c /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/src/my.cpp

CMakeFiles/ch08_drill.dir/src/my.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch08_drill.dir/src/my.cpp.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/src/my.cpp > CMakeFiles/ch08_drill.dir/src/my.cpp.i

CMakeFiles/ch08_drill.dir/src/my.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch08_drill.dir/src/my.cpp.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/src/my.cpp -o CMakeFiles/ch08_drill.dir/src/my.cpp.s

CMakeFiles/ch08_drill.dir/src/use.cpp.o: CMakeFiles/ch08_drill.dir/flags.make
CMakeFiles/ch08_drill.dir/src/use.cpp.o: ../src/use.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ch08_drill.dir/src/use.cpp.o"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch08_drill.dir/src/use.cpp.o -c /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/src/use.cpp

CMakeFiles/ch08_drill.dir/src/use.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch08_drill.dir/src/use.cpp.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/src/use.cpp > CMakeFiles/ch08_drill.dir/src/use.cpp.i

CMakeFiles/ch08_drill.dir/src/use.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch08_drill.dir/src/use.cpp.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/src/use.cpp -o CMakeFiles/ch08_drill.dir/src/use.cpp.s

# Object files for target ch08_drill
ch08_drill_OBJECTS = \
"CMakeFiles/ch08_drill.dir/src/my.cpp.o" \
"CMakeFiles/ch08_drill.dir/src/use.cpp.o"

# External object files for target ch08_drill
ch08_drill_EXTERNAL_OBJECTS =

ch08_drill: CMakeFiles/ch08_drill.dir/src/my.cpp.o
ch08_drill: CMakeFiles/ch08_drill.dir/src/use.cpp.o
ch08_drill: CMakeFiles/ch08_drill.dir/build.make
ch08_drill: CMakeFiles/ch08_drill.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ch08_drill"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch08_drill.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ch08_drill.dir/build: ch08_drill

.PHONY : CMakeFiles/ch08_drill.dir/build

CMakeFiles/ch08_drill.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ch08_drill.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ch08_drill.dir/clean

CMakeFiles/ch08_drill.dir/depend:
	cd /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08 /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08 /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch08/build/CMakeFiles/ch08_drill.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ch08_drill.dir/depend
