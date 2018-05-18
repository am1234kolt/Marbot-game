//
// Created by Saxion on 07/12/2017.
//

#ifndef ASSIGNMENT_04_GL_MAZE_H
#define ASSIGNMENT_04_GL_MAZE_H

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include "gl_object.h"
#include "gl_wall.h"
#include "gl_mineral.h"

class gl_maze : public gl_object {

public:
    using Pointi = std::pair<int, int>;

    gl_maze(const std::vector<Pointi>& walls, const std::vector<Pointi>& minerals):
            m_walls{},
            m_minerals{}
    {
        update(walls, minerals);
    }

    void update(const std::vector<Pointi>& walls, const std::vector<Pointi>& minerals){
        m_walls.clear();
        for (auto& p : walls){
            m_walls.emplace_back(p.first, p.second);
        }

        m_minerals.clear();
        for (auto& p : minerals){
            m_minerals.emplace_back(p.first, p.second);
        }

        set_scale(get_scale());
    }

    void set_scale(GLfloat scale) override {
        gl_object::set_scale(scale);
        std::for_each(m_walls.begin(), m_walls.end(), [scale=scale](gl_wall& wall){wall.set_scale(scale); });
        std::for_each(m_minerals.begin(), m_minerals.end(), [scale=scale](gl_mineral& mineral){mineral.set_scale(scale); });

    }

    void render() override {
        std::for_each(m_walls.begin(), m_walls.end(), [](gl_wall& wall){wall.render(); });
        std::for_each(m_minerals.begin(), m_minerals.end(), [](gl_mineral& mineral){mineral.render(); });
    }

private:

    std::vector<gl_wall> m_walls;
    std::vector<gl_mineral> m_minerals;
};


#endif //ASSIGNMENT_04_GL_MAZE_H
