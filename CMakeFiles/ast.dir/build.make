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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/monetanais/Desktop/ast/asteroide

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/monetanais/Desktop/ast/asteroide

# Include any dependencies generated for this target.
include CMakeFiles/ast.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ast.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ast.dir/flags.make

CMakeFiles/ast.dir/src/source.cpp.o: CMakeFiles/ast.dir/flags.make
CMakeFiles/ast.dir/src/source.cpp.o: src/source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ast.dir/src/source.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ast.dir/src/source.cpp.o -c /Users/monetanais/Desktop/ast/asteroide/src/source.cpp

CMakeFiles/ast.dir/src/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ast.dir/src/source.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/monetanais/Desktop/ast/asteroide/src/source.cpp > CMakeFiles/ast.dir/src/source.cpp.i

CMakeFiles/ast.dir/src/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ast.dir/src/source.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/monetanais/Desktop/ast/asteroide/src/source.cpp -o CMakeFiles/ast.dir/src/source.cpp.s

CMakeFiles/ast.dir/src/Asteroide.cpp.o: CMakeFiles/ast.dir/flags.make
CMakeFiles/ast.dir/src/Asteroide.cpp.o: src/Asteroide.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ast.dir/src/Asteroide.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ast.dir/src/Asteroide.cpp.o -c /Users/monetanais/Desktop/ast/asteroide/src/Asteroide.cpp

CMakeFiles/ast.dir/src/Asteroide.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ast.dir/src/Asteroide.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/monetanais/Desktop/ast/asteroide/src/Asteroide.cpp > CMakeFiles/ast.dir/src/Asteroide.cpp.i

CMakeFiles/ast.dir/src/Asteroide.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ast.dir/src/Asteroide.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/monetanais/Desktop/ast/asteroide/src/Asteroide.cpp -o CMakeFiles/ast.dir/src/Asteroide.cpp.s

CMakeFiles/ast.dir/src/Bullet.cpp.o: CMakeFiles/ast.dir/flags.make
CMakeFiles/ast.dir/src/Bullet.cpp.o: src/Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ast.dir/src/Bullet.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ast.dir/src/Bullet.cpp.o -c /Users/monetanais/Desktop/ast/asteroide/src/Bullet.cpp

CMakeFiles/ast.dir/src/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ast.dir/src/Bullet.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/monetanais/Desktop/ast/asteroide/src/Bullet.cpp > CMakeFiles/ast.dir/src/Bullet.cpp.i

CMakeFiles/ast.dir/src/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ast.dir/src/Bullet.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/monetanais/Desktop/ast/asteroide/src/Bullet.cpp -o CMakeFiles/ast.dir/src/Bullet.cpp.s

CMakeFiles/ast.dir/src/Game.cpp.o: CMakeFiles/ast.dir/flags.make
CMakeFiles/ast.dir/src/Game.cpp.o: src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ast.dir/src/Game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ast.dir/src/Game.cpp.o -c /Users/monetanais/Desktop/ast/asteroide/src/Game.cpp

CMakeFiles/ast.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ast.dir/src/Game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/monetanais/Desktop/ast/asteroide/src/Game.cpp > CMakeFiles/ast.dir/src/Game.cpp.i

CMakeFiles/ast.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ast.dir/src/Game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/monetanais/Desktop/ast/asteroide/src/Game.cpp -o CMakeFiles/ast.dir/src/Game.cpp.s

CMakeFiles/ast.dir/src/fonction.cpp.o: CMakeFiles/ast.dir/flags.make
CMakeFiles/ast.dir/src/fonction.cpp.o: src/fonction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ast.dir/src/fonction.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ast.dir/src/fonction.cpp.o -c /Users/monetanais/Desktop/ast/asteroide/src/fonction.cpp

CMakeFiles/ast.dir/src/fonction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ast.dir/src/fonction.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/monetanais/Desktop/ast/asteroide/src/fonction.cpp > CMakeFiles/ast.dir/src/fonction.cpp.i

CMakeFiles/ast.dir/src/fonction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ast.dir/src/fonction.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/monetanais/Desktop/ast/asteroide/src/fonction.cpp -o CMakeFiles/ast.dir/src/fonction.cpp.s

CMakeFiles/ast.dir/src/Texture.cpp.o: CMakeFiles/ast.dir/flags.make
CMakeFiles/ast.dir/src/Texture.cpp.o: src/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ast.dir/src/Texture.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ast.dir/src/Texture.cpp.o -c /Users/monetanais/Desktop/ast/asteroide/src/Texture.cpp

CMakeFiles/ast.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ast.dir/src/Texture.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/monetanais/Desktop/ast/asteroide/src/Texture.cpp > CMakeFiles/ast.dir/src/Texture.cpp.i

CMakeFiles/ast.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ast.dir/src/Texture.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/monetanais/Desktop/ast/asteroide/src/Texture.cpp -o CMakeFiles/ast.dir/src/Texture.cpp.s

CMakeFiles/ast.dir/src/vaisseau.cpp.o: CMakeFiles/ast.dir/flags.make
CMakeFiles/ast.dir/src/vaisseau.cpp.o: src/vaisseau.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ast.dir/src/vaisseau.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ast.dir/src/vaisseau.cpp.o -c /Users/monetanais/Desktop/ast/asteroide/src/vaisseau.cpp

CMakeFiles/ast.dir/src/vaisseau.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ast.dir/src/vaisseau.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/monetanais/Desktop/ast/asteroide/src/vaisseau.cpp > CMakeFiles/ast.dir/src/vaisseau.cpp.i

CMakeFiles/ast.dir/src/vaisseau.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ast.dir/src/vaisseau.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/monetanais/Desktop/ast/asteroide/src/vaisseau.cpp -o CMakeFiles/ast.dir/src/vaisseau.cpp.s

# Object files for target ast
ast_OBJECTS = \
"CMakeFiles/ast.dir/src/source.cpp.o" \
"CMakeFiles/ast.dir/src/Asteroide.cpp.o" \
"CMakeFiles/ast.dir/src/Bullet.cpp.o" \
"CMakeFiles/ast.dir/src/Game.cpp.o" \
"CMakeFiles/ast.dir/src/fonction.cpp.o" \
"CMakeFiles/ast.dir/src/Texture.cpp.o" \
"CMakeFiles/ast.dir/src/vaisseau.cpp.o"

# External object files for target ast
ast_EXTERNAL_OBJECTS =

ast: CMakeFiles/ast.dir/src/source.cpp.o
ast: CMakeFiles/ast.dir/src/Asteroide.cpp.o
ast: CMakeFiles/ast.dir/src/Bullet.cpp.o
ast: CMakeFiles/ast.dir/src/Game.cpp.o
ast: CMakeFiles/ast.dir/src/fonction.cpp.o
ast: CMakeFiles/ast.dir/src/Texture.cpp.o
ast: CMakeFiles/ast.dir/src/vaisseau.cpp.o
ast: CMakeFiles/ast.dir/build.make
ast: /usr/local/Cellar/sdl2/2.0.12_1/lib/libSDL2main.a
ast: /usr/local/Cellar/sdl2/2.0.12_1/lib/libSDL2.dylib
ast: CMakeFiles/ast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/monetanais/Desktop/ast/asteroide/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ast"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ast.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ast.dir/build: ast

.PHONY : CMakeFiles/ast.dir/build

CMakeFiles/ast.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ast.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ast.dir/clean

CMakeFiles/ast.dir/depend:
	cd /Users/monetanais/Desktop/ast/asteroide && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/monetanais/Desktop/ast/asteroide /Users/monetanais/Desktop/ast/asteroide /Users/monetanais/Desktop/ast/asteroide /Users/monetanais/Desktop/ast/asteroide /Users/monetanais/Desktop/ast/asteroide/CMakeFiles/ast.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ast.dir/depend

