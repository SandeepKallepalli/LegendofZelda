# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/vinky/sandeep/sem4/Graphics/LegendofZelda

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vinky/sandeep/sem4/Graphics/LegendofZelda/build

# Include any dependencies generated for this target.
include CMakeFiles/zelda.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zelda.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zelda.dir/flags.make

CMakeFiles/zelda.dir/src/barrel.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/barrel.cpp.o: ../src/barrel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zelda.dir/src/barrel.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/barrel.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/barrel.cpp

CMakeFiles/zelda.dir/src/barrel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/barrel.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/barrel.cpp > CMakeFiles/zelda.dir/src/barrel.cpp.i

CMakeFiles/zelda.dir/src/barrel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/barrel.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/barrel.cpp -o CMakeFiles/zelda.dir/src/barrel.cpp.s

CMakeFiles/zelda.dir/src/barrel.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/barrel.cpp.o.requires

CMakeFiles/zelda.dir/src/barrel.cpp.o.provides: CMakeFiles/zelda.dir/src/barrel.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/barrel.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/barrel.cpp.o.provides

CMakeFiles/zelda.dir/src/barrel.cpp.o.provides.build: CMakeFiles/zelda.dir/src/barrel.cpp.o


CMakeFiles/zelda.dir/src/ball.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/ball.cpp.o: ../src/ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zelda.dir/src/ball.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/ball.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/ball.cpp

CMakeFiles/zelda.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/ball.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/ball.cpp > CMakeFiles/zelda.dir/src/ball.cpp.i

CMakeFiles/zelda.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/ball.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/ball.cpp -o CMakeFiles/zelda.dir/src/ball.cpp.s

CMakeFiles/zelda.dir/src/ball.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/ball.cpp.o.requires

CMakeFiles/zelda.dir/src/ball.cpp.o.provides: CMakeFiles/zelda.dir/src/ball.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/ball.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/ball.cpp.o.provides

CMakeFiles/zelda.dir/src/ball.cpp.o.provides.build: CMakeFiles/zelda.dir/src/ball.cpp.o


CMakeFiles/zelda.dir/src/monster.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/monster.cpp.o: ../src/monster.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zelda.dir/src/monster.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/monster.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/monster.cpp

CMakeFiles/zelda.dir/src/monster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/monster.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/monster.cpp > CMakeFiles/zelda.dir/src/monster.cpp.i

CMakeFiles/zelda.dir/src/monster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/monster.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/monster.cpp -o CMakeFiles/zelda.dir/src/monster.cpp.s

CMakeFiles/zelda.dir/src/monster.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/monster.cpp.o.requires

CMakeFiles/zelda.dir/src/monster.cpp.o.provides: CMakeFiles/zelda.dir/src/monster.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/monster.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/monster.cpp.o.provides

CMakeFiles/zelda.dir/src/monster.cpp.o.provides.build: CMakeFiles/zelda.dir/src/monster.cpp.o


CMakeFiles/zelda.dir/src/timer.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/timer.cpp.o: ../src/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zelda.dir/src/timer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/timer.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/timer.cpp

CMakeFiles/zelda.dir/src/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/timer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/timer.cpp > CMakeFiles/zelda.dir/src/timer.cpp.i

CMakeFiles/zelda.dir/src/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/timer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/timer.cpp -o CMakeFiles/zelda.dir/src/timer.cpp.s

CMakeFiles/zelda.dir/src/timer.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/timer.cpp.o.requires

CMakeFiles/zelda.dir/src/timer.cpp.o.provides: CMakeFiles/zelda.dir/src/timer.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/timer.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/timer.cpp.o.provides

CMakeFiles/zelda.dir/src/timer.cpp.o.provides.build: CMakeFiles/zelda.dir/src/timer.cpp.o


CMakeFiles/zelda.dir/src/rock.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/rock.cpp.o: ../src/rock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zelda.dir/src/rock.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/rock.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/rock.cpp

CMakeFiles/zelda.dir/src/rock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/rock.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/rock.cpp > CMakeFiles/zelda.dir/src/rock.cpp.i

CMakeFiles/zelda.dir/src/rock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/rock.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/rock.cpp -o CMakeFiles/zelda.dir/src/rock.cpp.s

CMakeFiles/zelda.dir/src/rock.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/rock.cpp.o.requires

CMakeFiles/zelda.dir/src/rock.cpp.o.provides: CMakeFiles/zelda.dir/src/rock.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/rock.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/rock.cpp.o.provides

CMakeFiles/zelda.dir/src/rock.cpp.o.provides.build: CMakeFiles/zelda.dir/src/rock.cpp.o


CMakeFiles/zelda.dir/src/color.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/color.cpp.o: ../src/color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/zelda.dir/src/color.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/color.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/color.cpp

CMakeFiles/zelda.dir/src/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/color.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/color.cpp > CMakeFiles/zelda.dir/src/color.cpp.i

CMakeFiles/zelda.dir/src/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/color.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/color.cpp -o CMakeFiles/zelda.dir/src/color.cpp.s

CMakeFiles/zelda.dir/src/color.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/color.cpp.o.requires

CMakeFiles/zelda.dir/src/color.cpp.o.provides: CMakeFiles/zelda.dir/src/color.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/color.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/color.cpp.o.provides

CMakeFiles/zelda.dir/src/color.cpp.o.provides.build: CMakeFiles/zelda.dir/src/color.cpp.o


CMakeFiles/zelda.dir/src/man.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/man.cpp.o: ../src/man.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/zelda.dir/src/man.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/man.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/man.cpp

CMakeFiles/zelda.dir/src/man.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/man.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/man.cpp > CMakeFiles/zelda.dir/src/man.cpp.i

CMakeFiles/zelda.dir/src/man.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/man.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/man.cpp -o CMakeFiles/zelda.dir/src/man.cpp.s

CMakeFiles/zelda.dir/src/man.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/man.cpp.o.requires

CMakeFiles/zelda.dir/src/man.cpp.o.provides: CMakeFiles/zelda.dir/src/man.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/man.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/man.cpp.o.provides

CMakeFiles/zelda.dir/src/man.cpp.o.provides.build: CMakeFiles/zelda.dir/src/man.cpp.o


CMakeFiles/zelda.dir/src/input.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/input.cpp.o: ../src/input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/zelda.dir/src/input.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/input.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/input.cpp

CMakeFiles/zelda.dir/src/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/input.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/input.cpp > CMakeFiles/zelda.dir/src/input.cpp.i

CMakeFiles/zelda.dir/src/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/input.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/input.cpp -o CMakeFiles/zelda.dir/src/input.cpp.s

CMakeFiles/zelda.dir/src/input.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/input.cpp.o.requires

CMakeFiles/zelda.dir/src/input.cpp.o.provides: CMakeFiles/zelda.dir/src/input.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/input.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/input.cpp.o.provides

CMakeFiles/zelda.dir/src/input.cpp.o.provides.build: CMakeFiles/zelda.dir/src/input.cpp.o


CMakeFiles/zelda.dir/src/water.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/water.cpp.o: ../src/water.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/zelda.dir/src/water.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/water.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/water.cpp

CMakeFiles/zelda.dir/src/water.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/water.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/water.cpp > CMakeFiles/zelda.dir/src/water.cpp.i

CMakeFiles/zelda.dir/src/water.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/water.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/water.cpp -o CMakeFiles/zelda.dir/src/water.cpp.s

CMakeFiles/zelda.dir/src/water.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/water.cpp.o.requires

CMakeFiles/zelda.dir/src/water.cpp.o.provides: CMakeFiles/zelda.dir/src/water.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/water.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/water.cpp.o.provides

CMakeFiles/zelda.dir/src/water.cpp.o.provides.build: CMakeFiles/zelda.dir/src/water.cpp.o


CMakeFiles/zelda.dir/src/other_handlers.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/other_handlers.cpp.o: ../src/other_handlers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/zelda.dir/src/other_handlers.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/other_handlers.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/other_handlers.cpp

CMakeFiles/zelda.dir/src/other_handlers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/other_handlers.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/other_handlers.cpp > CMakeFiles/zelda.dir/src/other_handlers.cpp.i

CMakeFiles/zelda.dir/src/other_handlers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/other_handlers.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/other_handlers.cpp -o CMakeFiles/zelda.dir/src/other_handlers.cpp.s

CMakeFiles/zelda.dir/src/other_handlers.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/other_handlers.cpp.o.requires

CMakeFiles/zelda.dir/src/other_handlers.cpp.o.provides: CMakeFiles/zelda.dir/src/other_handlers.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/other_handlers.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/other_handlers.cpp.o.provides

CMakeFiles/zelda.dir/src/other_handlers.cpp.o.provides.build: CMakeFiles/zelda.dir/src/other_handlers.cpp.o


CMakeFiles/zelda.dir/src/sail.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/sail.cpp.o: ../src/sail.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/zelda.dir/src/sail.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/sail.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/sail.cpp

CMakeFiles/zelda.dir/src/sail.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/sail.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/sail.cpp > CMakeFiles/zelda.dir/src/sail.cpp.i

CMakeFiles/zelda.dir/src/sail.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/sail.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/sail.cpp -o CMakeFiles/zelda.dir/src/sail.cpp.s

CMakeFiles/zelda.dir/src/sail.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/sail.cpp.o.requires

CMakeFiles/zelda.dir/src/sail.cpp.o.provides: CMakeFiles/zelda.dir/src/sail.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/sail.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/sail.cpp.o.provides

CMakeFiles/zelda.dir/src/sail.cpp.o.provides.build: CMakeFiles/zelda.dir/src/sail.cpp.o


CMakeFiles/zelda.dir/src/nonedit.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/nonedit.cpp.o: ../src/nonedit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/zelda.dir/src/nonedit.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/nonedit.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/nonedit.cpp

CMakeFiles/zelda.dir/src/nonedit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/nonedit.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/nonedit.cpp > CMakeFiles/zelda.dir/src/nonedit.cpp.i

CMakeFiles/zelda.dir/src/nonedit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/nonedit.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/nonedit.cpp -o CMakeFiles/zelda.dir/src/nonedit.cpp.s

CMakeFiles/zelda.dir/src/nonedit.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/nonedit.cpp.o.requires

CMakeFiles/zelda.dir/src/nonedit.cpp.o.provides: CMakeFiles/zelda.dir/src/nonedit.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/nonedit.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/nonedit.cpp.o.provides

CMakeFiles/zelda.dir/src/nonedit.cpp.o.provides.build: CMakeFiles/zelda.dir/src/nonedit.cpp.o


CMakeFiles/zelda.dir/src/island.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/island.cpp.o: ../src/island.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/zelda.dir/src/island.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/island.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/island.cpp

CMakeFiles/zelda.dir/src/island.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/island.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/island.cpp > CMakeFiles/zelda.dir/src/island.cpp.i

CMakeFiles/zelda.dir/src/island.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/island.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/island.cpp -o CMakeFiles/zelda.dir/src/island.cpp.s

CMakeFiles/zelda.dir/src/island.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/island.cpp.o.requires

CMakeFiles/zelda.dir/src/island.cpp.o.provides: CMakeFiles/zelda.dir/src/island.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/island.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/island.cpp.o.provides

CMakeFiles/zelda.dir/src/island.cpp.o.provides.build: CMakeFiles/zelda.dir/src/island.cpp.o


CMakeFiles/zelda.dir/src/bullet.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/bullet.cpp.o: ../src/bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/zelda.dir/src/bullet.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/bullet.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/bullet.cpp

CMakeFiles/zelda.dir/src/bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/bullet.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/bullet.cpp > CMakeFiles/zelda.dir/src/bullet.cpp.i

CMakeFiles/zelda.dir/src/bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/bullet.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/bullet.cpp -o CMakeFiles/zelda.dir/src/bullet.cpp.s

CMakeFiles/zelda.dir/src/bullet.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/bullet.cpp.o.requires

CMakeFiles/zelda.dir/src/bullet.cpp.o.provides: CMakeFiles/zelda.dir/src/bullet.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/bullet.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/bullet.cpp.o.provides

CMakeFiles/zelda.dir/src/bullet.cpp.o.provides.build: CMakeFiles/zelda.dir/src/bullet.cpp.o


CMakeFiles/zelda.dir/src/main.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/zelda.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/main.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/main.cpp

CMakeFiles/zelda.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/main.cpp > CMakeFiles/zelda.dir/src/main.cpp.i

CMakeFiles/zelda.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/main.cpp -o CMakeFiles/zelda.dir/src/main.cpp.s

CMakeFiles/zelda.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/main.cpp.o.requires

CMakeFiles/zelda.dir/src/main.cpp.o.provides: CMakeFiles/zelda.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/main.cpp.o.provides

CMakeFiles/zelda.dir/src/main.cpp.o.provides.build: CMakeFiles/zelda.dir/src/main.cpp.o


CMakeFiles/zelda.dir/src/boat.cpp.o: CMakeFiles/zelda.dir/flags.make
CMakeFiles/zelda.dir/src/boat.cpp.o: ../src/boat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/zelda.dir/src/boat.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zelda.dir/src/boat.cpp.o -c /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/boat.cpp

CMakeFiles/zelda.dir/src/boat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zelda.dir/src/boat.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/boat.cpp > CMakeFiles/zelda.dir/src/boat.cpp.i

CMakeFiles/zelda.dir/src/boat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zelda.dir/src/boat.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vinky/sandeep/sem4/Graphics/LegendofZelda/src/boat.cpp -o CMakeFiles/zelda.dir/src/boat.cpp.s

CMakeFiles/zelda.dir/src/boat.cpp.o.requires:

.PHONY : CMakeFiles/zelda.dir/src/boat.cpp.o.requires

CMakeFiles/zelda.dir/src/boat.cpp.o.provides: CMakeFiles/zelda.dir/src/boat.cpp.o.requires
	$(MAKE) -f CMakeFiles/zelda.dir/build.make CMakeFiles/zelda.dir/src/boat.cpp.o.provides.build
.PHONY : CMakeFiles/zelda.dir/src/boat.cpp.o.provides

CMakeFiles/zelda.dir/src/boat.cpp.o.provides.build: CMakeFiles/zelda.dir/src/boat.cpp.o


# Object files for target zelda
zelda_OBJECTS = \
"CMakeFiles/zelda.dir/src/barrel.cpp.o" \
"CMakeFiles/zelda.dir/src/ball.cpp.o" \
"CMakeFiles/zelda.dir/src/monster.cpp.o" \
"CMakeFiles/zelda.dir/src/timer.cpp.o" \
"CMakeFiles/zelda.dir/src/rock.cpp.o" \
"CMakeFiles/zelda.dir/src/color.cpp.o" \
"CMakeFiles/zelda.dir/src/man.cpp.o" \
"CMakeFiles/zelda.dir/src/input.cpp.o" \
"CMakeFiles/zelda.dir/src/water.cpp.o" \
"CMakeFiles/zelda.dir/src/other_handlers.cpp.o" \
"CMakeFiles/zelda.dir/src/sail.cpp.o" \
"CMakeFiles/zelda.dir/src/nonedit.cpp.o" \
"CMakeFiles/zelda.dir/src/island.cpp.o" \
"CMakeFiles/zelda.dir/src/bullet.cpp.o" \
"CMakeFiles/zelda.dir/src/main.cpp.o" \
"CMakeFiles/zelda.dir/src/boat.cpp.o"

# External object files for target zelda
zelda_EXTERNAL_OBJECTS =

zelda: CMakeFiles/zelda.dir/src/barrel.cpp.o
zelda: CMakeFiles/zelda.dir/src/ball.cpp.o
zelda: CMakeFiles/zelda.dir/src/monster.cpp.o
zelda: CMakeFiles/zelda.dir/src/timer.cpp.o
zelda: CMakeFiles/zelda.dir/src/rock.cpp.o
zelda: CMakeFiles/zelda.dir/src/color.cpp.o
zelda: CMakeFiles/zelda.dir/src/man.cpp.o
zelda: CMakeFiles/zelda.dir/src/input.cpp.o
zelda: CMakeFiles/zelda.dir/src/water.cpp.o
zelda: CMakeFiles/zelda.dir/src/other_handlers.cpp.o
zelda: CMakeFiles/zelda.dir/src/sail.cpp.o
zelda: CMakeFiles/zelda.dir/src/nonedit.cpp.o
zelda: CMakeFiles/zelda.dir/src/island.cpp.o
zelda: CMakeFiles/zelda.dir/src/bullet.cpp.o
zelda: CMakeFiles/zelda.dir/src/main.cpp.o
zelda: CMakeFiles/zelda.dir/src/boat.cpp.o
zelda: CMakeFiles/zelda.dir/build.make
zelda: CMakeFiles/zelda.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable zelda"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zelda.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zelda.dir/build: zelda

.PHONY : CMakeFiles/zelda.dir/build

CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/barrel.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/ball.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/monster.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/timer.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/rock.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/color.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/man.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/input.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/water.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/other_handlers.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/sail.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/nonedit.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/island.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/bullet.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/main.cpp.o.requires
CMakeFiles/zelda.dir/requires: CMakeFiles/zelda.dir/src/boat.cpp.o.requires

.PHONY : CMakeFiles/zelda.dir/requires

CMakeFiles/zelda.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zelda.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zelda.dir/clean

CMakeFiles/zelda.dir/depend:
	cd /home/vinky/sandeep/sem4/Graphics/LegendofZelda/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vinky/sandeep/sem4/Graphics/LegendofZelda /home/vinky/sandeep/sem4/Graphics/LegendofZelda /home/vinky/sandeep/sem4/Graphics/LegendofZelda/build /home/vinky/sandeep/sem4/Graphics/LegendofZelda/build /home/vinky/sandeep/sem4/Graphics/LegendofZelda/build/CMakeFiles/zelda.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zelda.dir/depend
