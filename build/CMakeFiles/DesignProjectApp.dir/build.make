# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/christian/Documents/DesignProject/FYDP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/Documents/DesignProject/FYDP/build

# Include any dependencies generated for this target.
include CMakeFiles/DesignProjectApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DesignProjectApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DesignProjectApp.dir/flags.make

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/DesignProject/FYDP/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/main.cpp.o -c /home/christian/Documents/DesignProject/FYDP/src/main.cpp

CMakeFiles/DesignProjectApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/DesignProject/FYDP/src/main.cpp > CMakeFiles/DesignProjectApp.dir/src/main.cpp.i

CMakeFiles/DesignProjectApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/DesignProject/FYDP/src/main.cpp -o CMakeFiles/DesignProjectApp.dir/src/main.cpp.s

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/main.cpp.o

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o: ../src/Engine.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/DesignProject/FYDP/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o -c /home/christian/Documents/DesignProject/FYDP/src/Engine.cpp

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/DesignProject/FYDP/src/Engine.cpp > CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.i

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/DesignProject/FYDP/src/Engine.cpp -o CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.s

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o

CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o: ../src/RenderSystem.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/DesignProject/FYDP/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o -c /home/christian/Documents/DesignProject/FYDP/src/RenderSystem.cpp

CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/DesignProject/FYDP/src/RenderSystem.cpp > CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.i

CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/DesignProject/FYDP/src/RenderSystem.cpp -o CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.s

CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o

CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o: ../src/ResourceManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/DesignProject/FYDP/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o -c /home/christian/Documents/DesignProject/FYDP/src/ResourceManager.cpp

CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/DesignProject/FYDP/src/ResourceManager.cpp > CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.i

CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/DesignProject/FYDP/src/ResourceManager.cpp -o CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.s

CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o

CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o: ../src/Subject.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/DesignProject/FYDP/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o -c /home/christian/Documents/DesignProject/FYDP/src/Subject.cpp

CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/DesignProject/FYDP/src/Subject.cpp > CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.i

CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/DesignProject/FYDP/src/Subject.cpp -o CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.s

CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o

CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o: ../src/Entity.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/DesignProject/FYDP/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o -c /home/christian/Documents/DesignProject/FYDP/src/Entity.cpp

CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/DesignProject/FYDP/src/Entity.cpp > CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.i

CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/DesignProject/FYDP/src/Entity.cpp -o CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.s

CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o

# Object files for target DesignProjectApp
DesignProjectApp_OBJECTS = \
"CMakeFiles/DesignProjectApp.dir/src/main.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o"

# External object files for target DesignProjectApp
DesignProjectApp_EXTERNAL_OBJECTS =

dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/main.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/build.make
dist/bin/DesignProjectApp: /usr/local/lib/libOgreMain.so
dist/bin/DesignProjectApp: /usr/lib/libboost_thread-mt.so
dist/bin/DesignProjectApp: /usr/lib/libboost_date_time-mt.so
dist/bin/DesignProjectApp: /usr/lib/libboost_thread-mt.so
dist/bin/DesignProjectApp: /usr/lib/libboost_date_time-mt.so
dist/bin/DesignProjectApp: /usr/local/lib/libOgreTerrain.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libOIS.so
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable dist/bin/DesignProjectApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DesignProjectApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DesignProjectApp.dir/build: dist/bin/DesignProjectApp
.PHONY : CMakeFiles/DesignProjectApp.dir/build

CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.requires
CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.requires
CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/RenderSystem.cpp.o.requires
CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/ResourceManager.cpp.o.requires
CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/Subject.cpp.o.requires
CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/Entity.cpp.o.requires
.PHONY : CMakeFiles/DesignProjectApp.dir/requires

CMakeFiles/DesignProjectApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DesignProjectApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DesignProjectApp.dir/clean

CMakeFiles/DesignProjectApp.dir/depend:
	cd /home/christian/Documents/DesignProject/FYDP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/Documents/DesignProject/FYDP /home/christian/Documents/DesignProject/FYDP /home/christian/Documents/DesignProject/FYDP/build /home/christian/Documents/DesignProject/FYDP/build /home/christian/Documents/DesignProject/FYDP/build/CMakeFiles/DesignProjectApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DesignProjectApp.dir/depend

