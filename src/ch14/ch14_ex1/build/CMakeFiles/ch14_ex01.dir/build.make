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
CMAKE_SOURCE_DIR = /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build

# Include any dependencies generated for this target.
include CMakeFiles/ch14_ex01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ch14_ex01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ch14_ex01.dir/flags.make

CMakeFiles/ch14_ex01.dir/src/GUI.cpp.o: CMakeFiles/ch14_ex01.dir/flags.make
CMakeFiles/ch14_ex01.dir/src/GUI.cpp.o: ../src/GUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ch14_ex01.dir/src/GUI.cpp.o"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch14_ex01.dir/src/GUI.cpp.o -c /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/GUI.cpp

CMakeFiles/ch14_ex01.dir/src/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch14_ex01.dir/src/GUI.cpp.i"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/GUI.cpp > CMakeFiles/ch14_ex01.dir/src/GUI.cpp.i

CMakeFiles/ch14_ex01.dir/src/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch14_ex01.dir/src/GUI.cpp.s"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/GUI.cpp -o CMakeFiles/ch14_ex01.dir/src/GUI.cpp.s

CMakeFiles/ch14_ex01.dir/src/Graph.cpp.o: CMakeFiles/ch14_ex01.dir/flags.make
CMakeFiles/ch14_ex01.dir/src/Graph.cpp.o: ../src/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ch14_ex01.dir/src/Graph.cpp.o"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch14_ex01.dir/src/Graph.cpp.o -c /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Graph.cpp

CMakeFiles/ch14_ex01.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch14_ex01.dir/src/Graph.cpp.i"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Graph.cpp > CMakeFiles/ch14_ex01.dir/src/Graph.cpp.i

CMakeFiles/ch14_ex01.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch14_ex01.dir/src/Graph.cpp.s"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Graph.cpp -o CMakeFiles/ch14_ex01.dir/src/Graph.cpp.s

CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.o: CMakeFiles/ch14_ex01.dir/flags.make
CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.o: ../src/Simple_window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.o"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.o -c /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Simple_window.cpp

CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.i"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Simple_window.cpp > CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.i

CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.s"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Simple_window.cpp -o CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.s

CMakeFiles/ch14_ex01.dir/src/Window.cpp.o: CMakeFiles/ch14_ex01.dir/flags.make
CMakeFiles/ch14_ex01.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ch14_ex01.dir/src/Window.cpp.o"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch14_ex01.dir/src/Window.cpp.o -c /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Window.cpp

CMakeFiles/ch14_ex01.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch14_ex01.dir/src/Window.cpp.i"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Window.cpp > CMakeFiles/ch14_ex01.dir/src/Window.cpp.i

CMakeFiles/ch14_ex01.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch14_ex01.dir/src/Window.cpp.s"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/Window.cpp -o CMakeFiles/ch14_ex01.dir/src/Window.cpp.s

CMakeFiles/ch14_ex01.dir/src/main.cpp.o: CMakeFiles/ch14_ex01.dir/flags.make
CMakeFiles/ch14_ex01.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ch14_ex01.dir/src/main.cpp.o"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch14_ex01.dir/src/main.cpp.o -c /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/main.cpp

CMakeFiles/ch14_ex01.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch14_ex01.dir/src/main.cpp.i"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/main.cpp > CMakeFiles/ch14_ex01.dir/src/main.cpp.i

CMakeFiles/ch14_ex01.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch14_ex01.dir/src/main.cpp.s"
	/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/src/main.cpp -o CMakeFiles/ch14_ex01.dir/src/main.cpp.s

# Object files for target ch14_ex01
ch14_ex01_OBJECTS = \
"CMakeFiles/ch14_ex01.dir/src/GUI.cpp.o" \
"CMakeFiles/ch14_ex01.dir/src/Graph.cpp.o" \
"CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.o" \
"CMakeFiles/ch14_ex01.dir/src/Window.cpp.o" \
"CMakeFiles/ch14_ex01.dir/src/main.cpp.o"

# External object files for target ch14_ex01
ch14_ex01_EXTERNAL_OBJECTS =

ch14_ex01: CMakeFiles/ch14_ex01.dir/src/GUI.cpp.o
ch14_ex01: CMakeFiles/ch14_ex01.dir/src/Graph.cpp.o
ch14_ex01: CMakeFiles/ch14_ex01.dir/src/Simple_window.cpp.o
ch14_ex01: CMakeFiles/ch14_ex01.dir/src/Window.cpp.o
ch14_ex01: CMakeFiles/ch14_ex01.dir/src/main.cpp.o
ch14_ex01: CMakeFiles/ch14_ex01.dir/build.make
ch14_ex01: /usr/lib/x86_64-linux-gnu/libfltk.so
ch14_ex01: /usr/lib/x86_64-linux-gnu/libfltk_images.so
ch14_ex01: CMakeFiles/ch14_ex01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ch14_ex01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch14_ex01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ch14_ex01.dir/build: ch14_ex01

.PHONY : CMakeFiles/ch14_ex01.dir/build

CMakeFiles/ch14_ex01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ch14_ex01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ch14_ex01.dir/clean

CMakeFiles/ch14_ex01.dir/depend:
	cd /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1 /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1 /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build /home/jordi/Downloads/modern_c++/programming_principles_and_practice_using_c++/exercises/src/ch14/ch14_ex1/build/CMakeFiles/ch14_ex01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ch14_ex01.dir/depend

