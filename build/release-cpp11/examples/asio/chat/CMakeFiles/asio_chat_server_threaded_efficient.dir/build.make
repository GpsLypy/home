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
include examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/depend.make

# Include the progress variables for this target.
include examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/progress.make

# Include the compile flags for this target's objects.
include examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/flags.make

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o: examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/flags.make
examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o: /home/muduo/examples/asio/chat/server_threaded_efficient.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o"
	cd /home/build/release-cpp11/examples/asio/chat && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o -c /home/muduo/examples/asio/chat/server_threaded_efficient.cc

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.i"
	cd /home/build/release-cpp11/examples/asio/chat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muduo/examples/asio/chat/server_threaded_efficient.cc > CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.i

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.s"
	cd /home/build/release-cpp11/examples/asio/chat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muduo/examples/asio/chat/server_threaded_efficient.cc -o CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.s

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.requires:

.PHONY : examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.requires

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.provides: examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.requires
	$(MAKE) -f examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/build.make examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.provides.build
.PHONY : examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.provides

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.provides.build: examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o


# Object files for target asio_chat_server_threaded_efficient
asio_chat_server_threaded_efficient_OBJECTS = \
"CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o"

# External object files for target asio_chat_server_threaded_efficient
asio_chat_server_threaded_efficient_EXTERNAL_OBJECTS =

bin/asio_chat_server_threaded_efficient: examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o
bin/asio_chat_server_threaded_efficient: examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/build.make
bin/asio_chat_server_threaded_efficient: lib/libmuduo_net.a
bin/asio_chat_server_threaded_efficient: lib/libmuduo_base.a
bin/asio_chat_server_threaded_efficient: examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/build/release-cpp11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/asio_chat_server_threaded_efficient"
	cd /home/build/release-cpp11/examples/asio/chat && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/asio_chat_server_threaded_efficient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/build: bin/asio_chat_server_threaded_efficient

.PHONY : examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/build

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/requires: examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o.requires

.PHONY : examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/requires

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/clean:
	cd /home/build/release-cpp11/examples/asio/chat && $(CMAKE_COMMAND) -P CMakeFiles/asio_chat_server_threaded_efficient.dir/cmake_clean.cmake
.PHONY : examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/clean

examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/depend:
	cd /home/build/release-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muduo /home/muduo/examples/asio/chat /home/build/release-cpp11 /home/build/release-cpp11/examples/asio/chat /home/build/release-cpp11/examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/asio/chat/CMakeFiles/asio_chat_server_threaded_efficient.dir/depend
