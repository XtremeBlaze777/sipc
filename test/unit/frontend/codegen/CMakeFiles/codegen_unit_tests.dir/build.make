# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend

# Include any dependencies generated for this target.
include codegen/CMakeFiles/codegen_unit_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include codegen/CMakeFiles/codegen_unit_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include codegen/CMakeFiles/codegen_unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include codegen/CMakeFiles/codegen_unit_tests.dir/flags.make

codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o: codegen/CMakeFiles/codegen_unit_tests.dir/flags.make
codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o: ../codegen/CodegenFunctionsTest.cpp
codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o: codegen/CMakeFiles/codegen_unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o"
	cd /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/codegen && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o -MF CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o.d -o CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o -c /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/codegen/CodegenFunctionsTest.cpp

codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.i"
	cd /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/codegen && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/codegen/CodegenFunctionsTest.cpp > CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.i

codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.s"
	cd /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/codegen && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/codegen/CodegenFunctionsTest.cpp -o CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.s

# Object files for target codegen_unit_tests
codegen_unit_tests_OBJECTS = \
"CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o"

# External object files for target codegen_unit_tests
codegen_unit_tests_EXTERNAL_OBJECTS =

codegen/codegen_unit_tests: codegen/CMakeFiles/codegen_unit_tests.dir/CodegenFunctionsTest.o
codegen/codegen_unit_tests: codegen/CMakeFiles/codegen_unit_tests.dir/build.make
codegen/codegen_unit_tests: helpers/libtest_helpers.a
codegen/codegen_unit_tests: codegen/CMakeFiles/codegen_unit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable codegen_unit_tests"
	cd /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/codegen && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codegen_unit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
codegen/CMakeFiles/codegen_unit_tests.dir/build: codegen/codegen_unit_tests
.PHONY : codegen/CMakeFiles/codegen_unit_tests.dir/build

codegen/CMakeFiles/codegen_unit_tests.dir/clean:
	cd /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/codegen && $(CMAKE_COMMAND) -P CMakeFiles/codegen_unit_tests.dir/cmake_clean.cmake
.PHONY : codegen/CMakeFiles/codegen_unit_tests.dir/clean

codegen/CMakeFiles/codegen_unit_tests.dir/depend:
	cd /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/codegen /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/codegen /Users/neilphan/Desktop/cs4620/sipc-mathur_phan/test/unit/frontend/codegen/CMakeFiles/codegen_unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : codegen/CMakeFiles/codegen_unit_tests.dir/depend

