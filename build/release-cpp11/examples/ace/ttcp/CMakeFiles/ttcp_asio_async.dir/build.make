# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /home/muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/build/release-cpp11

# Include any dependencies generated for this target.
include examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/depend.make

# Include the progress variables for this target.
include examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/progress.make

# Include the compile flags for this target's objects.
include examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/flags.make

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/flags.make
examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o: /home/muduo/examples/ace/ttcp/ttcp_asio_async.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o -c /home/muduo/examples/ace/ttcp/ttcp_asio_async.cc

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.i"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muduo/examples/ace/ttcp/ttcp_asio_async.cc > CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.i

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.s"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muduo/examples/ace/ttcp/ttcp_asio_async.cc -o CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.s

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.requires:

.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.requires

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.provides: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.requires
	$(MAKE) -f examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/build.make examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.provides.build
.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.provides

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.provides.build: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o


examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/flags.make
examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o: /home/muduo/examples/ace/ttcp/common.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ttcp_asio_async.dir/common.cc.o -c /home/muduo/examples/ace/ttcp/common.cc

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ttcp_asio_async.dir/common.cc.i"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muduo/examples/ace/ttcp/common.cc > CMakeFiles/ttcp_asio_async.dir/common.cc.i

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ttcp_asio_async.dir/common.cc.s"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muduo/examples/ace/ttcp/common.cc -o CMakeFiles/ttcp_asio_async.dir/common.cc.s

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.requires:

.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.requires

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.provides: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.requires
	$(MAKE) -f examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/build.make examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.provides.build
.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.provides

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.provides.build: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o


examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/flags.make
examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o: /home/muduo/examples/ace/ttcp/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ttcp_asio_async.dir/main.cc.o -c /home/muduo/examples/ace/ttcp/main.cc

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ttcp_asio_async.dir/main.cc.i"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muduo/examples/ace/ttcp/main.cc > CMakeFiles/ttcp_asio_async.dir/main.cc.i

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ttcp_asio_async.dir/main.cc.s"
	cd /home/build/release-cpp11/examples/ace/ttcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muduo/examples/ace/ttcp/main.cc -o CMakeFiles/ttcp_asio_async.dir/main.cc.s

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.requires:

.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.requires

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.provides: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.requires
	$(MAKE) -f examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/build.make examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.provides.build
.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.provides

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.provides.build: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o


# Object files for target ttcp_asio_async
ttcp_asio_async_OBJECTS = \
"CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o" \
"CMakeFiles/ttcp_asio_async.dir/common.cc.o" \
"CMakeFiles/ttcp_asio_async.dir/main.cc.o"

# External object files for target ttcp_asio_async
ttcp_asio_async_EXTERNAL_OBJECTS =

bin/ttcp_asio_async: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o
bin/ttcp_asio_async: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o
bin/ttcp_asio_async: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o
bin/ttcp_asio_async: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/build.make
bin/ttcp_asio_async: lib/libmuduo_base.a
bin/ttcp_asio_async: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../bin/ttcp_asio_async"
	cd /home/build/release-cpp11/examples/ace/ttcp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ttcp_asio_async.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/build: bin/ttcp_asio_async

.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/build

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/requires: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/ttcp_asio_async.cc.o.requires
examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/requires: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/common.cc.o.requires
examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/requires: examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/main.cc.o.requires

.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/requires

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/clean:
	cd /home/build/release-cpp11/examples/ace/ttcp && $(CMAKE_COMMAND) -P CMakeFiles/ttcp_asio_async.dir/cmake_clean.cmake
.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/clean

examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/depend:
	cd /home/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muduo /home/muduo/examples/ace/ttcp /home/build/release-cpp11 /home/build/release-cpp11/examples/ace/ttcp /home/build/release-cpp11/examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/ace/ttcp/CMakeFiles/ttcp_asio_async.dir/depend

