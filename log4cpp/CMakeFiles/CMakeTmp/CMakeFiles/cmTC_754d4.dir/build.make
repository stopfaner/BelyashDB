# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp

# Include any dependencies generated for this target.
include CMakeFiles/cmTC_754d4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmTC_754d4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmTC_754d4.dir/flags.make

CMakeFiles/cmTC_754d4.dir/testCCompiler.c.o: CMakeFiles/cmTC_754d4.dir/flags.make
CMakeFiles/cmTC_754d4.dir/testCCompiler.c.o: testCCompiler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir=/Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cmTC_754d4.dir/testCCompiler.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cmTC_754d4.dir/testCCompiler.c.o   -c /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp/testCCompiler.c

CMakeFiles/cmTC_754d4.dir/testCCompiler.c.i: cmake_force
	@echo "Preprocessing C source to CMakeFiles/cmTC_754d4.dir/testCCompiler.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp/testCCompiler.c > CMakeFiles/cmTC_754d4.dir/testCCompiler.c.i

CMakeFiles/cmTC_754d4.dir/testCCompiler.c.s: cmake_force
	@echo "Compiling C source to assembly CMakeFiles/cmTC_754d4.dir/testCCompiler.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp/testCCompiler.c -o CMakeFiles/cmTC_754d4.dir/testCCompiler.c.s

# Object files for target cmTC_754d4
cmTC_754d4_OBJECTS = \
"CMakeFiles/cmTC_754d4.dir/testCCompiler.c.o"

# External object files for target cmTC_754d4
cmTC_754d4_EXTERNAL_OBJECTS =

cmTC_754d4: CMakeFiles/cmTC_754d4.dir/testCCompiler.c.o
cmTC_754d4: CMakeFiles/cmTC_754d4.dir/build.make
cmTC_754d4: CMakeFiles/cmTC_754d4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir=/Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cmTC_754d4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmTC_754d4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmTC_754d4.dir/build: cmTC_754d4

.PHONY : CMakeFiles/cmTC_754d4.dir/build

CMakeFiles/cmTC_754d4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmTC_754d4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmTC_754d4.dir/clean

CMakeFiles/cmTC_754d4.dir/depend:
	cd /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp /Users/dlytv/BelyashDB/log4cpp/CMakeFiles/CMakeTmp/CMakeFiles/cmTC_754d4.dir/DependInfo.cmake
.PHONY : CMakeFiles/cmTC_754d4.dir/depend

