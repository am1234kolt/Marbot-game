cmake_minimum_required(VERSION 3.8)
project(Assignment_05)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -Wextra -pedantic")
endif()

find_package(OpenGL REQUIRED)

add_subdirectory (glfw)



include_directories(glfw/include/GLFW/)
include_directories(gl/)

set(ALL_LIBS ${OPENGL_LIBRARY} glfw)

file(GLOB gl_sources "gl/*.cpp" "gl/*.h")


set(SOURCE_FILES main.cpp tunnel_map.cpp tunnel_map.h path_marbot.cpp path_marbot.h command_processor.h command_processor.cpp mineral_probe.cpp mineral_probe.h  maze.h pathfinder.h route.cpp route.h game.h game.cpp command_adapter.h mineral.h cargo.cpp cargo.h ${gl_sources} keyboard_reader.cpp keyboard_reader.h marbot.h command_adapter.cpp position_t.h martian.cpp martian.h direction.h cell_t.h manu_marbot.h manu_marbot.cpp)


configure_file(route route COPYONLY)
add_executable(Assignment_05 ${SOURCE_FILES})

target_link_libraries(Assignment_05 ${ALL_LIBS})