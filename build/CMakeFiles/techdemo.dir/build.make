# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = W:\Compilers\cmake\bin\cmake.exe

# The command to remove a file.
RM = W:\Compilers\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = W:\C++\Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = W:\C++\Engine\build

# Include any dependencies generated for this target.
include CMakeFiles/techdemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/techdemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/techdemo.dir/flags.make

CMakeFiles/techdemo.dir/source/main.cpp.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/source/main.cpp.obj: CMakeFiles/techdemo.dir/includes_CXX.rsp
CMakeFiles/techdemo.dir/source/main.cpp.obj: ../source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/techdemo.dir/source/main.cpp.obj"
	W:\Compilers\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\techdemo.dir\source\main.cpp.obj -c W:\C++\Engine\source\main.cpp

CMakeFiles/techdemo.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/techdemo.dir/source/main.cpp.i"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E W:\C++\Engine\source\main.cpp > CMakeFiles\techdemo.dir\source\main.cpp.i

CMakeFiles/techdemo.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/techdemo.dir/source/main.cpp.s"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S W:\C++\Engine\source\main.cpp -o CMakeFiles\techdemo.dir\source\main.cpp.s

CMakeFiles/techdemo.dir/source/main.cpp.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/source/main.cpp.obj.requires

CMakeFiles/techdemo.dir/source/main.cpp.obj.provides: CMakeFiles/techdemo.dir/source/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/source/main.cpp.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/source/main.cpp.obj.provides

CMakeFiles/techdemo.dir/source/main.cpp.obj.provides.build: CMakeFiles/techdemo.dir/source/main.cpp.obj


CMakeFiles/techdemo.dir/source/stb_image.cpp.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/source/stb_image.cpp.obj: CMakeFiles/techdemo.dir/includes_CXX.rsp
CMakeFiles/techdemo.dir/source/stb_image.cpp.obj: ../source/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/techdemo.dir/source/stb_image.cpp.obj"
	W:\Compilers\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\techdemo.dir\source\stb_image.cpp.obj -c W:\C++\Engine\source\stb_image.cpp

CMakeFiles/techdemo.dir/source/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/techdemo.dir/source/stb_image.cpp.i"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E W:\C++\Engine\source\stb_image.cpp > CMakeFiles\techdemo.dir\source\stb_image.cpp.i

CMakeFiles/techdemo.dir/source/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/techdemo.dir/source/stb_image.cpp.s"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S W:\C++\Engine\source\stb_image.cpp -o CMakeFiles\techdemo.dir\source\stb_image.cpp.s

CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.requires

CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.provides: CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.provides

CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.provides.build: CMakeFiles/techdemo.dir/source/stb_image.cpp.obj


CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj: CMakeFiles/techdemo.dir/includes_C.rsp
CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj: ../libraries/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj"
	W:\Compilers\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\techdemo.dir\libraries\glad\src\glad.c.obj   -c W:\C++\Engine\libraries\glad\src\glad.c

CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.i"
	W:\Compilers\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E W:\C++\Engine\libraries\glad\src\glad.c > CMakeFiles\techdemo.dir\libraries\glad\src\glad.c.i

CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.s"
	W:\Compilers\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S W:\C++\Engine\libraries\glad\src\glad.c -o CMakeFiles\techdemo.dir\libraries\glad\src\glad.c.s

CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.requires

CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.provides: CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.provides

CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.provides.build: CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj


CMakeFiles/techdemo.dir/source/Mesh.cpp.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/source/Mesh.cpp.obj: CMakeFiles/techdemo.dir/includes_CXX.rsp
CMakeFiles/techdemo.dir/source/Mesh.cpp.obj: ../source/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/techdemo.dir/source/Mesh.cpp.obj"
	W:\Compilers\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\techdemo.dir\source\Mesh.cpp.obj -c W:\C++\Engine\source\Mesh.cpp

CMakeFiles/techdemo.dir/source/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/techdemo.dir/source/Mesh.cpp.i"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E W:\C++\Engine\source\Mesh.cpp > CMakeFiles\techdemo.dir\source\Mesh.cpp.i

CMakeFiles/techdemo.dir/source/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/techdemo.dir/source/Mesh.cpp.s"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S W:\C++\Engine\source\Mesh.cpp -o CMakeFiles\techdemo.dir\source\Mesh.cpp.s

CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.requires

CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.provides: CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.provides

CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.provides.build: CMakeFiles/techdemo.dir/source/Mesh.cpp.obj


CMakeFiles/techdemo.dir/source/Model.cpp.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/source/Model.cpp.obj: CMakeFiles/techdemo.dir/includes_CXX.rsp
CMakeFiles/techdemo.dir/source/Model.cpp.obj: ../source/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/techdemo.dir/source/Model.cpp.obj"
	W:\Compilers\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\techdemo.dir\source\Model.cpp.obj -c W:\C++\Engine\source\Model.cpp

CMakeFiles/techdemo.dir/source/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/techdemo.dir/source/Model.cpp.i"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E W:\C++\Engine\source\Model.cpp > CMakeFiles\techdemo.dir\source\Model.cpp.i

CMakeFiles/techdemo.dir/source/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/techdemo.dir/source/Model.cpp.s"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S W:\C++\Engine\source\Model.cpp -o CMakeFiles\techdemo.dir\source\Model.cpp.s

CMakeFiles/techdemo.dir/source/Model.cpp.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/source/Model.cpp.obj.requires

CMakeFiles/techdemo.dir/source/Model.cpp.obj.provides: CMakeFiles/techdemo.dir/source/Model.cpp.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/source/Model.cpp.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/source/Model.cpp.obj.provides

CMakeFiles/techdemo.dir/source/Model.cpp.obj.provides.build: CMakeFiles/techdemo.dir/source/Model.cpp.obj


CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj: CMakeFiles/techdemo.dir/includes_CXX.rsp
CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj: ../source/OpenGL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj"
	W:\Compilers\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\techdemo.dir\source\OpenGL.cpp.obj -c W:\C++\Engine\source\OpenGL.cpp

CMakeFiles/techdemo.dir/source/OpenGL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/techdemo.dir/source/OpenGL.cpp.i"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E W:\C++\Engine\source\OpenGL.cpp > CMakeFiles\techdemo.dir\source\OpenGL.cpp.i

CMakeFiles/techdemo.dir/source/OpenGL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/techdemo.dir/source/OpenGL.cpp.s"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S W:\C++\Engine\source\OpenGL.cpp -o CMakeFiles\techdemo.dir\source\OpenGL.cpp.s

CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.requires

CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.provides: CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.provides

CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.provides.build: CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj


CMakeFiles/techdemo.dir/source/GameObject.cpp.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/source/GameObject.cpp.obj: CMakeFiles/techdemo.dir/includes_CXX.rsp
CMakeFiles/techdemo.dir/source/GameObject.cpp.obj: ../source/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/techdemo.dir/source/GameObject.cpp.obj"
	W:\Compilers\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\techdemo.dir\source\GameObject.cpp.obj -c W:\C++\Engine\source\GameObject.cpp

CMakeFiles/techdemo.dir/source/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/techdemo.dir/source/GameObject.cpp.i"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E W:\C++\Engine\source\GameObject.cpp > CMakeFiles\techdemo.dir\source\GameObject.cpp.i

CMakeFiles/techdemo.dir/source/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/techdemo.dir/source/GameObject.cpp.s"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S W:\C++\Engine\source\GameObject.cpp -o CMakeFiles\techdemo.dir\source\GameObject.cpp.s

CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.requires

CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.provides: CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.provides

CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.provides.build: CMakeFiles/techdemo.dir/source/GameObject.cpp.obj


CMakeFiles/techdemo.dir/source/Skybox.cpp.obj: CMakeFiles/techdemo.dir/flags.make
CMakeFiles/techdemo.dir/source/Skybox.cpp.obj: CMakeFiles/techdemo.dir/includes_CXX.rsp
CMakeFiles/techdemo.dir/source/Skybox.cpp.obj: ../source/Skybox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/techdemo.dir/source/Skybox.cpp.obj"
	W:\Compilers\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\techdemo.dir\source\Skybox.cpp.obj -c W:\C++\Engine\source\Skybox.cpp

CMakeFiles/techdemo.dir/source/Skybox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/techdemo.dir/source/Skybox.cpp.i"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E W:\C++\Engine\source\Skybox.cpp > CMakeFiles\techdemo.dir\source\Skybox.cpp.i

CMakeFiles/techdemo.dir/source/Skybox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/techdemo.dir/source/Skybox.cpp.s"
	W:\Compilers\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S W:\C++\Engine\source\Skybox.cpp -o CMakeFiles\techdemo.dir\source\Skybox.cpp.s

CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.requires:

.PHONY : CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.requires

CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.provides: CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.requires
	$(MAKE) -f CMakeFiles\techdemo.dir\build.make CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.provides.build
.PHONY : CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.provides

CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.provides.build: CMakeFiles/techdemo.dir/source/Skybox.cpp.obj


# Object files for target techdemo
techdemo_OBJECTS = \
"CMakeFiles/techdemo.dir/source/main.cpp.obj" \
"CMakeFiles/techdemo.dir/source/stb_image.cpp.obj" \
"CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj" \
"CMakeFiles/techdemo.dir/source/Mesh.cpp.obj" \
"CMakeFiles/techdemo.dir/source/Model.cpp.obj" \
"CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj" \
"CMakeFiles/techdemo.dir/source/GameObject.cpp.obj" \
"CMakeFiles/techdemo.dir/source/Skybox.cpp.obj"

# External object files for target techdemo
techdemo_EXTERNAL_OBJECTS =

techdemo.exe: CMakeFiles/techdemo.dir/source/main.cpp.obj
techdemo.exe: CMakeFiles/techdemo.dir/source/stb_image.cpp.obj
techdemo.exe: CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj
techdemo.exe: CMakeFiles/techdemo.dir/source/Mesh.cpp.obj
techdemo.exe: CMakeFiles/techdemo.dir/source/Model.cpp.obj
techdemo.exe: CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj
techdemo.exe: CMakeFiles/techdemo.dir/source/GameObject.cpp.obj
techdemo.exe: CMakeFiles/techdemo.dir/source/Skybox.cpp.obj
techdemo.exe: CMakeFiles/techdemo.dir/build.make
techdemo.exe: CMakeFiles/techdemo.dir/linklibs.rsp
techdemo.exe: CMakeFiles/techdemo.dir/objects1.rsp
techdemo.exe: CMakeFiles/techdemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=W:\C++\Engine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable techdemo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\techdemo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/techdemo.dir/build: techdemo.exe

.PHONY : CMakeFiles/techdemo.dir/build

CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/source/main.cpp.obj.requires
CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/source/stb_image.cpp.obj.requires
CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/libraries/glad/src/glad.c.obj.requires
CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/source/Mesh.cpp.obj.requires
CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/source/Model.cpp.obj.requires
CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/source/OpenGL.cpp.obj.requires
CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/source/GameObject.cpp.obj.requires
CMakeFiles/techdemo.dir/requires: CMakeFiles/techdemo.dir/source/Skybox.cpp.obj.requires

.PHONY : CMakeFiles/techdemo.dir/requires

CMakeFiles/techdemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\techdemo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/techdemo.dir/clean

CMakeFiles/techdemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" W:\C++\Engine W:\C++\Engine W:\C++\Engine\build W:\C++\Engine\build W:\C++\Engine\build\CMakeFiles\techdemo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/techdemo.dir/depend

