

#ifndef GAME_H
#define GAME_H


#include <memory>
#include "gl_martian.h"
#include "gl_maze.h"
#include "maze.h"
#include "gl_main.h"
#include "mineral_probe.h"
#include "marbot.h"
#include "gl_robot.h"
#include "route.h"
#include "pathfinder.h"
#include "command_processor.h"
#include "command_adapter.h"
#include "keyboard_reader.h"
#include "martian.h"
#include "tunnel_map.h"


class game {
public:
    explicit game(int robot_choice);

    void initialize();
    void run();


private:
    maze<20> m_maze;
    std::shared_ptr<gl_maze>  m_sp_gmaze;
    gl_main  m_gmain;
    pathfinder m_pathfinder;
    route m_route;

    command_processor m_cp;
    tunnel_map m_map;
    std::shared_ptr<mineral_probe> m_sp_probe;
    keyboard_reader m_kreader;

    std::shared_ptr<gl_robot> m_sp_grobot;
    std::shared_ptr<command_adapter> m_sp_adaptor;

    std::unique_ptr<marbot> m_up_robot;

    std::vector<std::shared_ptr<gl_martian>> m_sp_gmartians;
    std::vector<martian> m_martians;

};


#endif
