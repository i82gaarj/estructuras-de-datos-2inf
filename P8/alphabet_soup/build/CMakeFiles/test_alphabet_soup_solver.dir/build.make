# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/i82gaarj/Desktop/alphabet_soup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/i82gaarj/Desktop/alphabet_soup/build

# Include any dependencies generated for this target.
include CMakeFiles/test_alphabet_soup_solver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_alphabet_soup_solver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_alphabet_soup_solver.dir/flags.make

CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.o: CMakeFiles/test_alphabet_soup_solver.dir/flags.make
CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.o: ../test_alphabet_soup_solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i82gaarj/Desktop/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.o -c /home/i82gaarj/Desktop/alphabet_soup/test_alphabet_soup_solver.cpp

CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i82gaarj/Desktop/alphabet_soup/test_alphabet_soup_solver.cpp > CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.i

CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i82gaarj/Desktop/alphabet_soup/test_alphabet_soup_solver.cpp -o CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.s

CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.o: CMakeFiles/test_alphabet_soup_solver.dir/flags.make
CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.o: ../alphabet_soup_solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i82gaarj/Desktop/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.o -c /home/i82gaarj/Desktop/alphabet_soup/alphabet_soup_solver.cpp

CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i82gaarj/Desktop/alphabet_soup/alphabet_soup_solver.cpp > CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.i

CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i82gaarj/Desktop/alphabet_soup/alphabet_soup_solver.cpp -o CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.s

CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.o: CMakeFiles/test_alphabet_soup_solver.dir/flags.make
CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.o: ../trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i82gaarj/Desktop/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.o -c /home/i82gaarj/Desktop/alphabet_soup/trie.cpp

CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i82gaarj/Desktop/alphabet_soup/trie.cpp > CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.i

CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i82gaarj/Desktop/alphabet_soup/trie.cpp -o CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.s

# Object files for target test_alphabet_soup_solver
test_alphabet_soup_solver_OBJECTS = \
"CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.o" \
"CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.o" \
"CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.o"

# External object files for target test_alphabet_soup_solver
test_alphabet_soup_solver_EXTERNAL_OBJECTS =

test_alphabet_soup_solver: CMakeFiles/test_alphabet_soup_solver.dir/test_alphabet_soup_solver.cpp.o
test_alphabet_soup_solver: CMakeFiles/test_alphabet_soup_solver.dir/alphabet_soup_solver.cpp.o
test_alphabet_soup_solver: CMakeFiles/test_alphabet_soup_solver.dir/trie.cpp.o
test_alphabet_soup_solver: CMakeFiles/test_alphabet_soup_solver.dir/build.make
test_alphabet_soup_solver: CMakeFiles/test_alphabet_soup_solver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/i82gaarj/Desktop/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_alphabet_soup_solver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_alphabet_soup_solver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_alphabet_soup_solver.dir/build: test_alphabet_soup_solver

.PHONY : CMakeFiles/test_alphabet_soup_solver.dir/build

CMakeFiles/test_alphabet_soup_solver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_alphabet_soup_solver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_alphabet_soup_solver.dir/clean

CMakeFiles/test_alphabet_soup_solver.dir/depend:
	cd /home/i82gaarj/Desktop/alphabet_soup/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/i82gaarj/Desktop/alphabet_soup /home/i82gaarj/Desktop/alphabet_soup /home/i82gaarj/Desktop/alphabet_soup/build /home/i82gaarj/Desktop/alphabet_soup/build /home/i82gaarj/Desktop/alphabet_soup/build/CMakeFiles/test_alphabet_soup_solver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_alphabet_soup_solver.dir/depend

