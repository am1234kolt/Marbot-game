//
// Created by Saxion on 04/12/2017.
//

#ifndef ASSIGNMENT_GL_GL_ROBOT_H
#define ASSIGNMENT_GL_GL_ROBOT_H

#include "gl_object.h"

#include <utility>
#include <functional>
#include <cmath>
#include <iostream>

#include "GLFW/glfw3.h"
#include "../position_t.h"
class gl_robot : public gl_object {
public:


    explicit gl_robot(double size=1.);

    double x() const { return m_x; }
    double y() const { return m_y; }
    std::pair<double, double> position() const { return std::make_pair(m_x, m_y); };

    void set_position(position_t position);
    void render() override;

private:

    double m_x;
    double m_y;
    double m_size;
    double m_rotation;
};


#endif //ASSIGNMENT_GL_GL_ROBOT_H
