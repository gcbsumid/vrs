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
CMAKE_SOURCE_DIR = /home/christian/Documents/VRS/vrs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/Documents/VRS/vrs/build

# Include any dependencies generated for this target.
include CMakeFiles/DesignProjectApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DesignProjectApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DesignProjectApp.dir/flags.make

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/VRS/vrs/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/main.cpp.o -c /home/christian/Documents/VRS/vrs/src/main.cpp

CMakeFiles/DesignProjectApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/VRS/vrs/src/main.cpp > CMakeFiles/DesignProjectApp.dir/src/main.cpp.i

CMakeFiles/DesignProjectApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/VRS/vrs/src/main.cpp -o CMakeFiles/DesignProjectApp.dir/src/main.cpp.s

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/main.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/main.cpp.o

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o: ../src/Engine.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/VRS/vrs/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o -c /home/christian/Documents/VRS/vrs/src/Engine.cpp

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/VRS/vrs/src/Engine.cpp > CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.i

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/VRS/vrs/src/Engine.cpp -o CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.s

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o: ../src/RenderSystem/RenderSystem.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/VRS/vrs/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o -c /home/christian/Documents/VRS/vrs/src/RenderSystem/RenderSystem.cpp

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/VRS/vrs/src/RenderSystem/RenderSystem.cpp > CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.i

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/VRS/vrs/src/RenderSystem/RenderSystem.cpp -o CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.s

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o: CMakeFiles/DesignProjectApp.dir/flags.make
CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o: ../src/RenderSystem/ResourceManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/christian/Documents/VRS/vrs/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o -c /home/christian/Documents/VRS/vrs/src/RenderSystem/ResourceManager.cpp

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/christian/Documents/VRS/vrs/src/RenderSystem/ResourceManager.cpp > CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.i

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/christian/Documents/VRS/vrs/src/RenderSystem/ResourceManager.cpp -o CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.s

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.requires:
.PHONY : CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.requires

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.provides: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/DesignProjectApp.dir/build.make CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.provides.build
.PHONY : CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.provides

CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.provides.build: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o

# Object files for target DesignProjectApp
DesignProjectApp_OBJECTS = \
"CMakeFiles/DesignProjectApp.dir/src/main.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o" \
"CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o"

# External object files for target DesignProjectApp
DesignProjectApp_EXTERNAL_OBJECTS =

dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/main.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/Engine.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o
dist/bin/DesignProjectApp: CMakeFiles/DesignProjectApp.dir/build.make
dist/bin/DesignProjectApp: /usr/local/lib/libOgreMain.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_thread.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_system.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libpthread.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_thread.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_system.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
dist/bin/DesignProjectApp: /usr/lib/x86_64-linux-gnu/libpthread.so
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
CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/RenderSystem.cpp.o.requires
CMakeFiles/DesignProjectApp.dir/requires: CMakeFiles/DesignProjectApp.dir/src/RenderSystem/ResourceManager.cpp.o.requires
.PHONY : CMakeFiles/DesignProjectApp.dir/requires

CMakeFiles/DesignProjectApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DesignProjectApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DesignProjectApp.dir/clean

CMakeFiles/DesignProjectApp.dir/depend:
	cd /home/christian/Documents/VRS/vrs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/Documents/VRS/vrs /home/christian/Documents/VRS/vrs /home/christian/Documents/VRS/vrs/build /home/christian/Documents/VRS/vrs/build /home/christian/Documents/VRS/vrs/build/CMakeFiles/DesignProjectApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DesignProjectApp.dir/depend

