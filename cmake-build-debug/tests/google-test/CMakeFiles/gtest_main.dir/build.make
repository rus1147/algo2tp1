# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\algo2tp1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\algo2tp1\cmake-build-debug

# Include any dependencies generated for this target.
include tests/google-test/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include tests/google-test/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/google-test/CMakeFiles/gtest_main.dir/flags.make

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: tests/google-test/CMakeFiles/gtest_main.dir/flags.make
tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: tests/google-test/CMakeFiles/gtest_main.dir/includes_CXX.rsp
tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: ../tests/google-test/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\algo2tp1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"
	cd /d D:\algo2tp1\cmake-build-debug\tests\google-test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.obj -c D:\algo2tp1\tests\google-test\src\gtest_main.cc

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /d D:\algo2tp1\cmake-build-debug\tests\google-test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\algo2tp1\tests\google-test\src\gtest_main.cc > CMakeFiles\gtest_main.dir\src\gtest_main.cc.i

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /d D:\algo2tp1\cmake-build-debug\tests\google-test && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\algo2tp1\tests\google-test\src\gtest_main.cc -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.s

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires:

.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires
	$(MAKE) -f tests\google-test\CMakeFiles\gtest_main.dir\build.make tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides.build
.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides

tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.provides.build: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

tests/google-test/libgtest_main.a: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj
tests/google-test/libgtest_main.a: tests/google-test/CMakeFiles/gtest_main.dir/build.make
tests/google-test/libgtest_main.a: tests/google-test/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\algo2tp1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /d D:\algo2tp1\cmake-build-debug\tests\google-test && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean_target.cmake
	cd /d D:\algo2tp1\cmake-build-debug\tests\google-test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/google-test/CMakeFiles/gtest_main.dir/build: tests/google-test/libgtest_main.a

.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/build

tests/google-test/CMakeFiles/gtest_main.dir/requires: tests/google-test/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.requires

.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/requires

tests/google-test/CMakeFiles/gtest_main.dir/clean:
	cd /d D:\algo2tp1\cmake-build-debug\tests\google-test && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean.cmake
.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/clean

tests/google-test/CMakeFiles/gtest_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\algo2tp1 D:\algo2tp1\tests\google-test D:\algo2tp1\cmake-build-debug D:\algo2tp1\cmake-build-debug\tests\google-test D:\algo2tp1\cmake-build-debug\tests\google-test\CMakeFiles\gtest_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/google-test/CMakeFiles/gtest_main.dir/depend

