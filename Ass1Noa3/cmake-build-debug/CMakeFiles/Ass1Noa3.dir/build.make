# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/sf_SPL/Ass1Noa3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_SPL/Ass1Noa3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ass1Noa3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Ass1Noa3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ass1Noa3.dir/flags.make

CMakeFiles/Ass1Noa3.dir/src/main.cpp.o: CMakeFiles/Ass1Noa3.dir/flags.make
CMakeFiles/Ass1Noa3.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ass1Noa3.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1Noa3.dir/src/main.cpp.o -c /media/sf_SPL/Ass1Noa3/src/main.cpp

CMakeFiles/Ass1Noa3.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1Noa3.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_SPL/Ass1Noa3/src/main.cpp > CMakeFiles/Ass1Noa3.dir/src/main.cpp.i

CMakeFiles/Ass1Noa3.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1Noa3.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_SPL/Ass1Noa3/src/main.cpp -o CMakeFiles/Ass1Noa3.dir/src/main.cpp.s

CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.o: CMakeFiles/Ass1Noa3.dir/flags.make
CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.o: ../src/Studio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.o -c /media/sf_SPL/Ass1Noa3/src/Studio.cpp

CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_SPL/Ass1Noa3/src/Studio.cpp > CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.i

CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_SPL/Ass1Noa3/src/Studio.cpp -o CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.s

CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.o: CMakeFiles/Ass1Noa3.dir/flags.make
CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.o: ../src/Workout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.o -c /media/sf_SPL/Ass1Noa3/src/Workout.cpp

CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_SPL/Ass1Noa3/src/Workout.cpp > CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.i

CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_SPL/Ass1Noa3/src/Workout.cpp -o CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.s

CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.o: CMakeFiles/Ass1Noa3.dir/flags.make
CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.o: ../src/Trainer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.o -c /media/sf_SPL/Ass1Noa3/src/Trainer.cpp

CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_SPL/Ass1Noa3/src/Trainer.cpp > CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.i

CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_SPL/Ass1Noa3/src/Trainer.cpp -o CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.s

CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.o: CMakeFiles/Ass1Noa3.dir/flags.make
CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.o: ../src/Customer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.o -c /media/sf_SPL/Ass1Noa3/src/Customer.cpp

CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_SPL/Ass1Noa3/src/Customer.cpp > CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.i

CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_SPL/Ass1Noa3/src/Customer.cpp -o CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.s

CMakeFiles/Ass1Noa3.dir/src/Action.cpp.o: CMakeFiles/Ass1Noa3.dir/flags.make
CMakeFiles/Ass1Noa3.dir/src/Action.cpp.o: ../src/Action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Ass1Noa3.dir/src/Action.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ass1Noa3.dir/src/Action.cpp.o -c /media/sf_SPL/Ass1Noa3/src/Action.cpp

CMakeFiles/Ass1Noa3.dir/src/Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ass1Noa3.dir/src/Action.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_SPL/Ass1Noa3/src/Action.cpp > CMakeFiles/Ass1Noa3.dir/src/Action.cpp.i

CMakeFiles/Ass1Noa3.dir/src/Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ass1Noa3.dir/src/Action.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_SPL/Ass1Noa3/src/Action.cpp -o CMakeFiles/Ass1Noa3.dir/src/Action.cpp.s

# Object files for target Ass1Noa3
Ass1Noa3_OBJECTS = \
"CMakeFiles/Ass1Noa3.dir/src/main.cpp.o" \
"CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.o" \
"CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.o" \
"CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.o" \
"CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.o" \
"CMakeFiles/Ass1Noa3.dir/src/Action.cpp.o"

# External object files for target Ass1Noa3
Ass1Noa3_EXTERNAL_OBJECTS =

Ass1Noa3: CMakeFiles/Ass1Noa3.dir/src/main.cpp.o
Ass1Noa3: CMakeFiles/Ass1Noa3.dir/src/Studio.cpp.o
Ass1Noa3: CMakeFiles/Ass1Noa3.dir/src/Workout.cpp.o
Ass1Noa3: CMakeFiles/Ass1Noa3.dir/src/Trainer.cpp.o
Ass1Noa3: CMakeFiles/Ass1Noa3.dir/src/Customer.cpp.o
Ass1Noa3: CMakeFiles/Ass1Noa3.dir/src/Action.cpp.o
Ass1Noa3: CMakeFiles/Ass1Noa3.dir/build.make
Ass1Noa3: CMakeFiles/Ass1Noa3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Ass1Noa3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ass1Noa3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ass1Noa3.dir/build: Ass1Noa3
.PHONY : CMakeFiles/Ass1Noa3.dir/build

CMakeFiles/Ass1Noa3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ass1Noa3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ass1Noa3.dir/clean

CMakeFiles/Ass1Noa3.dir/depend:
	cd /media/sf_SPL/Ass1Noa3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_SPL/Ass1Noa3 /media/sf_SPL/Ass1Noa3 /media/sf_SPL/Ass1Noa3/cmake-build-debug /media/sf_SPL/Ass1Noa3/cmake-build-debug /media/sf_SPL/Ass1Noa3/cmake-build-debug/CMakeFiles/Ass1Noa3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ass1Noa3.dir/depend

