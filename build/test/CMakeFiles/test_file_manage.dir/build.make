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
CMAKE_COMMAND = /usr/local/lib/python3.8/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.8/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_file_manage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_file_manage.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_file_manage.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_file_manage.dir/flags.make

test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o: test/CMakeFiles/test_file_manage.dir/flags.make
test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o: ../test/test_file_manage.cpp
test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o: test/CMakeFiles/test_file_manage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o -MF CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o.d -o CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o -c /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/test/test_file_manage.cpp

test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_file_manage.dir/test_file_manage.cpp.i"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/test/test_file_manage.cpp > CMakeFiles/test_file_manage.dir/test_file_manage.cpp.i

test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_file_manage.dir/test_file_manage.cpp.s"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/test/test_file_manage.cpp -o CMakeFiles/test_file_manage.dir/test_file_manage.cpp.s

test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o: test/CMakeFiles/test_file_manage.dir/flags.make
test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o: ../src/disk.cpp
test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o: test/CMakeFiles/test_file_manage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o -MF CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o.d -o CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o -c /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/disk.cpp

test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_file_manage.dir/__/src/disk.cpp.i"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/disk.cpp > CMakeFiles/test_file_manage.dir/__/src/disk.cpp.i

test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_file_manage.dir/__/src/disk.cpp.s"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/disk.cpp -o CMakeFiles/test_file_manage.dir/__/src/disk.cpp.s

test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o: test/CMakeFiles/test_file_manage.dir/flags.make
test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o: ../src/block_io.cpp
test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o: test/CMakeFiles/test_file_manage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o -MF CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o.d -o CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o -c /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/block_io.cpp

test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.i"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/block_io.cpp > CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.i

test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.s"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/block_io.cpp -o CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.s

test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o: test/CMakeFiles/test_file_manage.dir/flags.make
test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o: ../src/terminal_io.cpp
test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o: test/CMakeFiles/test_file_manage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o -MF CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o.d -o CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o -c /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/terminal_io.cpp

test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.i"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/terminal_io.cpp > CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.i

test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.s"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/terminal_io.cpp -o CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.s

# Object files for target test_file_manage
test_file_manage_OBJECTS = \
"CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o" \
"CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o" \
"CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o" \
"CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o"

# External object files for target test_file_manage
test_file_manage_EXTERNAL_OBJECTS =

test/test_file_manage: test/CMakeFiles/test_file_manage.dir/test_file_manage.cpp.o
test/test_file_manage: test/CMakeFiles/test_file_manage.dir/__/src/disk.cpp.o
test/test_file_manage: test/CMakeFiles/test_file_manage.dir/__/src/block_io.cpp.o
test/test_file_manage: test/CMakeFiles/test_file_manage.dir/__/src/terminal_io.cpp.o
test/test_file_manage: test/CMakeFiles/test_file_manage.dir/build.make
test/test_file_manage: /usr/local/lib/libboost_filesystem.so.1.80.0
test/test_file_manage: /usr/local/lib/libboost_system.so.1.80.0
test/test_file_manage: /usr/local/lib/libboost_unit_test_framework.so.1.80.0
test/test_file_manage: /usr/local/lib/libboost_atomic.so.1.80.0
test/test_file_manage: test/CMakeFiles/test_file_manage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable test_file_manage"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_file_manage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_file_manage.dir/build: test/test_file_manage
.PHONY : test/CMakeFiles/test_file_manage.dir/build

test/CMakeFiles/test_file_manage.dir/clean:
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_file_manage.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_file_manage.dir/clean

test/CMakeFiles/test_file_manage.dir/depend:
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/test /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/test/CMakeFiles/test_file_manage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_file_manage.dir/depend
