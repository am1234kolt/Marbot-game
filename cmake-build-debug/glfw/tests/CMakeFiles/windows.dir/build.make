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
include glfw/tests/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include glfw/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include glfw/tests/CMakeFiles/windows.dir/flags.make

glfw/tests/CMakeFiles/windows.dir/windows.c.obj: glfw/tests/CMakeFiles/windows.dir/flags.make
glfw/tests/CMakeFiles/windows.dir/windows.c.obj: glfw/tests/CMakeFiles/windows.dir/includes_C.rsp
glfw/tests/CMakeFiles/windows.dir/windows.c.obj: ../glfw/tests/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw/tests/CMakeFiles/windows.dir/windows.c.obj"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\windows.dir\windows.c.obj   -c "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\tests\windows.c"

glfw/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\tests\windows.c" > CMakeFiles\windows.dir\windows.c.i

glfw/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\tests\windows.c" -o CMakeFiles\windows.dir\windows.c.s

glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires:

.PHONY : glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires

glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides: glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires
	$(MAKE) -f glfw\tests\CMakeFiles\windows.dir\build.make glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides.build
.PHONY : glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides

glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides.build: glfw/tests/CMakeFiles/windows.dir/windows.c.obj


glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj: glfw/tests/CMakeFiles/windows.dir/flags.make
glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj: glfw/tests/CMakeFiles/windows.dir/includes_C.rsp
glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj: ../glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\windows.dir\__\deps\getopt.c.obj   -c "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\getopt.c"

glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/getopt.c.i"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\getopt.c" > CMakeFiles\windows.dir\__\deps\getopt.c.i

glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/getopt.c.s"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\getopt.c" -o CMakeFiles\windows.dir\__\deps\getopt.c.s

glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires:

.PHONY : glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires

glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides: glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f glfw\tests\CMakeFiles\windows.dir\build.make glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides.build
.PHONY : glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides

glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides.build: glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj


glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj: glfw/tests/CMakeFiles/windows.dir/flags.make
glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj: glfw/tests/CMakeFiles/windows.dir/includes_C.rsp
glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj: ../glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\windows.dir\__\deps\glad.c.obj   -c "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\glad.c"

glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/glad.c.i"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\glad.c" > CMakeFiles\windows.dir\__\deps\glad.c.i

glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/glad.c.s"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\deps\glad.c" -o CMakeFiles\windows.dir\__\deps\glad.c.s

glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires:

.PHONY : glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires

glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides: glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f glfw\tests\CMakeFiles\windows.dir\build.make glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides.build
.PHONY : glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides

glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides.build: glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj


# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.obj" \
"CMakeFiles/windows.dir/__/deps/getopt.c.obj" \
"CMakeFiles/windows.dir/__/deps/glad.c.obj"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

glfw/tests/windows.exe: glfw/tests/CMakeFiles/windows.dir/windows.c.obj
glfw/tests/windows.exe: glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj
glfw/tests/windows.exe: glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj
glfw/tests/windows.exe: glfw/tests/CMakeFiles/windows.dir/build.make
glfw/tests/windows.exe: glfw/src/libglfw3.a
glfw/tests/windows.exe: glfw/tests/CMakeFiles/windows.dir/linklibs.rsp
glfw/tests/windows.exe: glfw/tests/CMakeFiles/windows.dir/objects1.rsp
glfw/tests/windows.exe: glfw/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable windows.exe"
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\windows.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw/tests/CMakeFiles/windows.dir/build: glfw/tests/windows.exe

.PHONY : glfw/tests/CMakeFiles/windows.dir/build

glfw/tests/CMakeFiles/windows.dir/requires: glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires
glfw/tests/CMakeFiles/windows.dir/requires: glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires
glfw/tests/CMakeFiles/windows.dir/requires: glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires

.PHONY : glfw/tests/CMakeFiles/windows.dir/requires

glfw/tests/CMakeFiles/windows.dir/clean:
	cd /d C:\Users\Saxion\OneDrive\Teaching\Code\PROGRA~1\ASSIGN~1\ASSIGN~2\CMAKE-~1\glfw\tests && $(CMAKE_COMMAND) -P CMakeFiles\windows.dir\cmake_clean.cmake
.PHONY : glfw/tests/CMakeFiles/windows.dir/clean

glfw/tests/CMakeFiles/windows.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\glfw\tests" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\glfw\tests" "C:\Users\Saxion\OneDrive\Teaching\Code\Programming in Cpp\Assignments\Assignment 04\cmake-build-debug\glfw\tests\CMakeFiles\windows.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : glfw/tests/CMakeFiles/windows.dir/depend

