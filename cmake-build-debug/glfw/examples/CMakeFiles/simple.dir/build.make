# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug"

# Include any dependencies generated for this target.
include glfw/examples/CMakeFiles/simple.dir/depend.make

# Include the progress variables for this target.
include glfw/examples/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include glfw/examples/CMakeFiles/simple.dir/flags.make

glfw/examples/CMakeFiles/simple.dir/simple.c.obj: glfw/examples/CMakeFiles/simple.dir/flags.make
glfw/examples/CMakeFiles/simple.dir/simple.c.obj: glfw/examples/CMakeFiles/simple.dir/includes_C.rsp
glfw/examples/CMakeFiles/simple.dir/simple.c.obj: ../glfw/examples/simple.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw/examples/CMakeFiles/simple.dir/simple.c.obj"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simple.dir\simple.c.obj   -c "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\examples\simple.c"

glfw/examples/CMakeFiles/simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/simple.c.i"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\examples\simple.c" > CMakeFiles\simple.dir\simple.c.i

glfw/examples/CMakeFiles/simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/simple.c.s"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\examples\simple.c" -o CMakeFiles\simple.dir\simple.c.s

glfw/examples/CMakeFiles/simple.dir/simple.c.obj.requires:

.PHONY : glfw/examples/CMakeFiles/simple.dir/simple.c.obj.requires

glfw/examples/CMakeFiles/simple.dir/simple.c.obj.provides: glfw/examples/CMakeFiles/simple.dir/simple.c.obj.requires
	$(MAKE) -f glfw\examples\CMakeFiles\simple.dir\build.make glfw/examples/CMakeFiles/simple.dir/simple.c.obj.provides.build
.PHONY : glfw/examples/CMakeFiles/simple.dir/simple.c.obj.provides

glfw/examples/CMakeFiles/simple.dir/simple.c.obj.provides.build: glfw/examples/CMakeFiles/simple.dir/simple.c.obj


glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj: glfw/examples/CMakeFiles/simple.dir/flags.make
glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj: ../glfw/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building RC object glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && C:\mingw64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\examples\glfw.rc" CMakeFiles\simple.dir\glfw.rc.obj

glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.requires:

.PHONY : glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.requires

glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.provides: glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.requires
	$(MAKE) -f glfw\examples\CMakeFiles\simple.dir\build.make glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.provides.build
.PHONY : glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.provides

glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.provides.build: glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj


glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj: glfw/examples/CMakeFiles/simple.dir/flags.make
glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj: glfw/examples/CMakeFiles/simple.dir/includes_C.rsp
glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj: ../glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simple.dir\__\deps\glad.c.obj   -c "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\glad.c"

glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/__/deps/glad.c.i"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\glad.c" > CMakeFiles\simple.dir\__\deps\glad.c.i

glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/__/deps/glad.c.s"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\glad.c" -o CMakeFiles\simple.dir\__\deps\glad.c.s

glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.requires:

.PHONY : glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.requires

glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.provides: glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f glfw\examples\CMakeFiles\simple.dir\build.make glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.provides.build
.PHONY : glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.provides

glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.provides.build: glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj


# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.c.obj" \
"CMakeFiles/simple.dir/glfw.rc.obj" \
"CMakeFiles/simple.dir/__/deps/glad.c.obj"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

glfw/examples/simple.exe: glfw/examples/CMakeFiles/simple.dir/simple.c.obj
glfw/examples/simple.exe: glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj
glfw/examples/simple.exe: glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj
glfw/examples/simple.exe: glfw/examples/CMakeFiles/simple.dir/build.make
glfw/examples/simple.exe: glfw/src/libglfw3.a
glfw/examples/simple.exe: glfw/examples/CMakeFiles/simple.dir/linklibs.rsp
glfw/examples/simple.exe: glfw/examples/CMakeFiles/simple.dir/objects1.rsp
glfw/examples/simple.exe: glfw/examples/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable simple.exe"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\simple.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw/examples/CMakeFiles/simple.dir/build: glfw/examples/simple.exe

.PHONY : glfw/examples/CMakeFiles/simple.dir/build

glfw/examples/CMakeFiles/simple.dir/requires: glfw/examples/CMakeFiles/simple.dir/simple.c.obj.requires
glfw/examples/CMakeFiles/simple.dir/requires: glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj.requires
glfw/examples/CMakeFiles/simple.dir/requires: glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.obj.requires

.PHONY : glfw/examples/CMakeFiles/simple.dir/requires

glfw/examples/CMakeFiles/simple.dir/clean:
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\examples && $(CMAKE_COMMAND) -P CMakeFiles\simple.dir\cmake_clean.cmake
.PHONY : glfw/examples/CMakeFiles/simple.dir/clean

glfw/examples/CMakeFiles/simple.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\examples" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\glfw\examples" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\glfw\examples\CMakeFiles\simple.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : glfw/examples/CMakeFiles/simple.dir/depend
