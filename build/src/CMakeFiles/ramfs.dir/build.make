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
include src/CMakeFiles/ramfs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/ramfs.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ramfs.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ramfs.dir/flags.make

src/CMakeFiles/ramfs.dir/ramfs.cpp.o: src/CMakeFiles/ramfs.dir/flags.make
src/CMakeFiles/ramfs.dir/ramfs.cpp.o: ../src/ramfs.cpp
src/CMakeFiles/ramfs.dir/ramfs.cpp.o: src/CMakeFiles/ramfs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ramfs.dir/ramfs.cpp.o"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ramfs.dir/ramfs.cpp.o -MF CMakeFiles/ramfs.dir/ramfs.cpp.o.d -o CMakeFiles/ramfs.dir/ramfs.cpp.o -c /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/ramfs.cpp

src/CMakeFiles/ramfs.dir/ramfs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ramfs.dir/ramfs.cpp.i"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/ramfs.cpp > CMakeFiles/ramfs.dir/ramfs.cpp.i

src/CMakeFiles/ramfs.dir/ramfs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ramfs.dir/ramfs.cpp.s"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/ramfs.cpp -o CMakeFiles/ramfs.dir/ramfs.cpp.s

src/CMakeFiles/ramfs.dir/disk.cpp.o: src/CMakeFiles/ramfs.dir/flags.make
src/CMakeFiles/ramfs.dir/disk.cpp.o: ../src/disk.cpp
src/CMakeFiles/ramfs.dir/disk.cpp.o: src/CMakeFiles/ramfs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ramfs.dir/disk.cpp.o"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ramfs.dir/disk.cpp.o -MF CMakeFiles/ramfs.dir/disk.cpp.o.d -o CMakeFiles/ramfs.dir/disk.cpp.o -c /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/disk.cpp

src/CMakeFiles/ramfs.dir/disk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ramfs.dir/disk.cpp.i"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/disk.cpp > CMakeFiles/ramfs.dir/disk.cpp.i

src/CMakeFiles/ramfs.dir/disk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ramfs.dir/disk.cpp.s"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/disk.cpp -o CMakeFiles/ramfs.dir/disk.cpp.s

src/CMakeFiles/ramfs.dir/terminal_io.cpp.o: src/CMakeFiles/ramfs.dir/flags.make
src/CMakeFiles/ramfs.dir/terminal_io.cpp.o: ../src/terminal_io.cpp
src/CMakeFiles/ramfs.dir/terminal_io.cpp.o: src/CMakeFiles/ramfs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ramfs.dir/terminal_io.cpp.o"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ramfs.dir/terminal_io.cpp.o -MF CMakeFiles/ramfs.dir/terminal_io.cpp.o.d -o CMakeFiles/ramfs.dir/terminal_io.cpp.o -c /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/terminal_io.cpp

src/CMakeFiles/ramfs.dir/terminal_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ramfs.dir/terminal_io.cpp.i"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/terminal_io.cpp > CMakeFiles/ramfs.dir/terminal_io.cpp.i

src/CMakeFiles/ramfs.dir/terminal_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ramfs.dir/terminal_io.cpp.s"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src/terminal_io.cpp -o CMakeFiles/ramfs.dir/terminal_io.cpp.s

# Object files for target ramfs
ramfs_OBJECTS = \
"CMakeFiles/ramfs.dir/ramfs.cpp.o" \
"CMakeFiles/ramfs.dir/disk.cpp.o" \
"CMakeFiles/ramfs.dir/terminal_io.cpp.o"

# External object files for target ramfs
ramfs_EXTERNAL_OBJECTS =

src/ramfs: src/CMakeFiles/ramfs.dir/ramfs.cpp.o
src/ramfs: src/CMakeFiles/ramfs.dir/disk.cpp.o
src/ramfs: src/CMakeFiles/ramfs.dir/terminal_io.cpp.o
src/ramfs: src/CMakeFiles/ramfs.dir/build.make
src/ramfs: src/CMakeFiles/ramfs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ramfs"
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ramfs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ramfs.dir/build: src/ramfs
.PHONY : src/CMakeFiles/ramfs.dir/build

src/CMakeFiles/ramfs.dir/clean:
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ramfs.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ramfs.dir/clean

src/CMakeFiles/ramfs.dir/depend:
	cd /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/src /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src /home/david/study/course/22-23-1/os/exp/exp3_file-system/simple_ram_fs/build/src/CMakeFiles/ramfs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ramfs.dir/depend
