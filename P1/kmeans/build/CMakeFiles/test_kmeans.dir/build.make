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
CMAKE_SOURCE_DIR = /home/i82gaarj/Desktop/i82gaarj/kmeans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/i82gaarj/Desktop/i82gaarj/kmeans/build

# Include any dependencies generated for this target.
include CMakeFiles/test_kmeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_kmeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_kmeans.dir/flags.make

CMakeFiles/test_kmeans.dir/test_kmeans.cpp.o: CMakeFiles/test_kmeans.dir/flags.make
CMakeFiles/test_kmeans.dir/test_kmeans.cpp.o: ../test_kmeans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i82gaarj/Desktop/i82gaarj/kmeans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_kmeans.dir/test_kmeans.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_kmeans.dir/test_kmeans.cpp.o -c /home/i82gaarj/Desktop/i82gaarj/kmeans/test_kmeans.cpp

CMakeFiles/test_kmeans.dir/test_kmeans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_kmeans.dir/test_kmeans.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i82gaarj/Desktop/i82gaarj/kmeans/test_kmeans.cpp > CMakeFiles/test_kmeans.dir/test_kmeans.cpp.i

CMakeFiles/test_kmeans.dir/test_kmeans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_kmeans.dir/test_kmeans.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i82gaarj/Desktop/i82gaarj/kmeans/test_kmeans.cpp -o CMakeFiles/test_kmeans.dir/test_kmeans.cpp.s

CMakeFiles/test_kmeans.dir/kmeans.cpp.o: CMakeFiles/test_kmeans.dir/flags.make
CMakeFiles/test_kmeans.dir/kmeans.cpp.o: ../kmeans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i82gaarj/Desktop/i82gaarj/kmeans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_kmeans.dir/kmeans.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_kmeans.dir/kmeans.cpp.o -c /home/i82gaarj/Desktop/i82gaarj/kmeans/kmeans.cpp

CMakeFiles/test_kmeans.dir/kmeans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_kmeans.dir/kmeans.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i82gaarj/Desktop/i82gaarj/kmeans/kmeans.cpp > CMakeFiles/test_kmeans.dir/kmeans.cpp.i

CMakeFiles/test_kmeans.dir/kmeans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_kmeans.dir/kmeans.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i82gaarj/Desktop/i82gaarj/kmeans/kmeans.cpp -o CMakeFiles/test_kmeans.dir/kmeans.cpp.s

CMakeFiles/test_kmeans.dir/pattern.cpp.o: CMakeFiles/test_kmeans.dir/flags.make
CMakeFiles/test_kmeans.dir/pattern.cpp.o: ../pattern.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/i82gaarj/Desktop/i82gaarj/kmeans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_kmeans.dir/pattern.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_kmeans.dir/pattern.cpp.o -c /home/i82gaarj/Desktop/i82gaarj/kmeans/pattern.cpp

CMakeFiles/test_kmeans.dir/pattern.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_kmeans.dir/pattern.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/i82gaarj/Desktop/i82gaarj/kmeans/pattern.cpp > CMakeFiles/test_kmeans.dir/pattern.cpp.i

CMakeFiles/test_kmeans.dir/pattern.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_kmeans.dir/pattern.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/i82gaarj/Desktop/i82gaarj/kmeans/pattern.cpp -o CMakeFiles/test_kmeans.dir/pattern.cpp.s

# Object files for target test_kmeans
test_kmeans_OBJECTS = \
"CMakeFiles/test_kmeans.dir/test_kmeans.cpp.o" \
"CMakeFiles/test_kmeans.dir/kmeans.cpp.o" \
"CMakeFiles/test_kmeans.dir/pattern.cpp.o"

# External object files for target test_kmeans
test_kmeans_EXTERNAL_OBJECTS =

test_kmeans: CMakeFiles/test_kmeans.dir/test_kmeans.cpp.o
test_kmeans: CMakeFiles/test_kmeans.dir/kmeans.cpp.o
test_kmeans: CMakeFiles/test_kmeans.dir/pattern.cpp.o
test_kmeans: CMakeFiles/test_kmeans.dir/build.make
test_kmeans: CMakeFiles/test_kmeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/i82gaarj/Desktop/i82gaarj/kmeans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_kmeans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_kmeans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_kmeans.dir/build: test_kmeans

.PHONY : CMakeFiles/test_kmeans.dir/build

CMakeFiles/test_kmeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_kmeans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_kmeans.dir/clean

CMakeFiles/test_kmeans.dir/depend:
	cd /home/i82gaarj/Desktop/i82gaarj/kmeans/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/i82gaarj/Desktop/i82gaarj/kmeans /home/i82gaarj/Desktop/i82gaarj/kmeans /home/i82gaarj/Desktop/i82gaarj/kmeans/build /home/i82gaarj/Desktop/i82gaarj/kmeans/build /home/i82gaarj/Desktop/i82gaarj/kmeans/build/CMakeFiles/test_kmeans.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_kmeans.dir/depend

