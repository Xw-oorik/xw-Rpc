# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oorik/桌面/rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oorik/桌面/rpc/build

# Include any dependencies generated for this target.
include src/CMakeFiles/rpc.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/rpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/rpc.dir/flags.make

src/CMakeFiles/rpc.dir/logger.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/logger.cc.o: ../src/logger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/rpc.dir/logger.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/logger.cc.o -c /home/oorik/桌面/rpc/src/logger.cc

src/CMakeFiles/rpc.dir/logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/logger.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/logger.cc > CMakeFiles/rpc.dir/logger.cc.i

src/CMakeFiles/rpc.dir/logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/logger.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/logger.cc -o CMakeFiles/rpc.dir/logger.cc.s

src/CMakeFiles/rpc.dir/rpc.pb.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpc.pb.cc.o: ../src/rpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/rpc.dir/rpc.pb.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/rpc.pb.cc.o -c /home/oorik/桌面/rpc/src/rpc.pb.cc

src/CMakeFiles/rpc.dir/rpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpc.pb.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/rpc.pb.cc > CMakeFiles/rpc.dir/rpc.pb.cc.i

src/CMakeFiles/rpc.dir/rpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpc.pb.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/rpc.pb.cc -o CMakeFiles/rpc.dir/rpc.pb.cc.s

src/CMakeFiles/rpc.dir/rpcapplication.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcapplication.cc.o: ../src/rpcapplication.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/rpc.dir/rpcapplication.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/rpcapplication.cc.o -c /home/oorik/桌面/rpc/src/rpcapplication.cc

src/CMakeFiles/rpc.dir/rpcapplication.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcapplication.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/rpcapplication.cc > CMakeFiles/rpc.dir/rpcapplication.cc.i

src/CMakeFiles/rpc.dir/rpcapplication.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcapplication.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/rpcapplication.cc -o CMakeFiles/rpc.dir/rpcapplication.cc.s

src/CMakeFiles/rpc.dir/rpcchannel.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcchannel.cc.o: ../src/rpcchannel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/rpc.dir/rpcchannel.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/rpcchannel.cc.o -c /home/oorik/桌面/rpc/src/rpcchannel.cc

src/CMakeFiles/rpc.dir/rpcchannel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcchannel.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/rpcchannel.cc > CMakeFiles/rpc.dir/rpcchannel.cc.i

src/CMakeFiles/rpc.dir/rpcchannel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcchannel.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/rpcchannel.cc -o CMakeFiles/rpc.dir/rpcchannel.cc.s

src/CMakeFiles/rpc.dir/rpcconfig.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcconfig.cc.o: ../src/rpcconfig.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/rpc.dir/rpcconfig.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/rpcconfig.cc.o -c /home/oorik/桌面/rpc/src/rpcconfig.cc

src/CMakeFiles/rpc.dir/rpcconfig.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcconfig.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/rpcconfig.cc > CMakeFiles/rpc.dir/rpcconfig.cc.i

src/CMakeFiles/rpc.dir/rpcconfig.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcconfig.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/rpcconfig.cc -o CMakeFiles/rpc.dir/rpcconfig.cc.s

src/CMakeFiles/rpc.dir/rpccontroller.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpccontroller.cc.o: ../src/rpccontroller.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/rpc.dir/rpccontroller.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/rpccontroller.cc.o -c /home/oorik/桌面/rpc/src/rpccontroller.cc

src/CMakeFiles/rpc.dir/rpccontroller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpccontroller.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/rpccontroller.cc > CMakeFiles/rpc.dir/rpccontroller.cc.i

src/CMakeFiles/rpc.dir/rpccontroller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpccontroller.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/rpccontroller.cc -o CMakeFiles/rpc.dir/rpccontroller.cc.s

src/CMakeFiles/rpc.dir/rpcprovider.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/rpcprovider.cc.o: ../src/rpcprovider.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/rpc.dir/rpcprovider.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/rpcprovider.cc.o -c /home/oorik/桌面/rpc/src/rpcprovider.cc

src/CMakeFiles/rpc.dir/rpcprovider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/rpcprovider.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/rpcprovider.cc > CMakeFiles/rpc.dir/rpcprovider.cc.i

src/CMakeFiles/rpc.dir/rpcprovider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/rpcprovider.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/rpcprovider.cc -o CMakeFiles/rpc.dir/rpcprovider.cc.s

src/CMakeFiles/rpc.dir/zookeeperClient.cc.o: src/CMakeFiles/rpc.dir/flags.make
src/CMakeFiles/rpc.dir/zookeeperClient.cc.o: ../src/zookeeperClient.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/rpc.dir/zookeeperClient.cc.o"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc.dir/zookeeperClient.cc.o -c /home/oorik/桌面/rpc/src/zookeeperClient.cc

src/CMakeFiles/rpc.dir/zookeeperClient.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc.dir/zookeeperClient.cc.i"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oorik/桌面/rpc/src/zookeeperClient.cc > CMakeFiles/rpc.dir/zookeeperClient.cc.i

src/CMakeFiles/rpc.dir/zookeeperClient.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc.dir/zookeeperClient.cc.s"
	cd /home/oorik/桌面/rpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oorik/桌面/rpc/src/zookeeperClient.cc -o CMakeFiles/rpc.dir/zookeeperClient.cc.s

# Object files for target rpc
rpc_OBJECTS = \
"CMakeFiles/rpc.dir/logger.cc.o" \
"CMakeFiles/rpc.dir/rpc.pb.cc.o" \
"CMakeFiles/rpc.dir/rpcapplication.cc.o" \
"CMakeFiles/rpc.dir/rpcchannel.cc.o" \
"CMakeFiles/rpc.dir/rpcconfig.cc.o" \
"CMakeFiles/rpc.dir/rpccontroller.cc.o" \
"CMakeFiles/rpc.dir/rpcprovider.cc.o" \
"CMakeFiles/rpc.dir/zookeeperClient.cc.o"

# External object files for target rpc
rpc_EXTERNAL_OBJECTS =

../lib/librpc.a: src/CMakeFiles/rpc.dir/logger.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpc.pb.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcapplication.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcchannel.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcconfig.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpccontroller.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/rpcprovider.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/zookeeperClient.cc.o
../lib/librpc.a: src/CMakeFiles/rpc.dir/build.make
../lib/librpc.a: src/CMakeFiles/rpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oorik/桌面/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library ../../lib/librpc.a"
	cd /home/oorik/桌面/rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/rpc.dir/cmake_clean_target.cmake
	cd /home/oorik/桌面/rpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/rpc.dir/build: ../lib/librpc.a

.PHONY : src/CMakeFiles/rpc.dir/build

src/CMakeFiles/rpc.dir/clean:
	cd /home/oorik/桌面/rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/rpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/rpc.dir/clean

src/CMakeFiles/rpc.dir/depend:
	cd /home/oorik/桌面/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oorik/桌面/rpc /home/oorik/桌面/rpc/src /home/oorik/桌面/rpc/build /home/oorik/桌面/rpc/build/src /home/oorik/桌面/rpc/build/src/CMakeFiles/rpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/rpc.dir/depend
