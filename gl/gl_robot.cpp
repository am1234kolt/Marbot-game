//
// Created by Saxion on 07/12/2017.
//

#include "gl_robot.h"

gl_robot::gl_robot(double size)  :
        m_x{0.},
        m_y{0.},
        m_size{size},
        m_rotation{0.}
{}

void gl_robot::render() {

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix();

    glScaled(m_size*get_scale(), m_size*get_scale(), 1);
    glTranslated(m_x+.5, m_y+0.5, 0);
    glScaled(0.5, 0.5 , 1);

    glRotated(-90., 0, 0, 1.0);
    glRotated(m_rotation, 0, 0, 1.0);

    glBegin(GL_TRIANGLE_FAN);
    {
        glColor3f(0 / 255.f, 84.f / 255.f, 192.f / 255.f);
        glVertex2d(0, 0);
        glColor3f(0 / 255.f, 32.f / 255.f, 64.f / 255.f);
        for (double alpha = 0; alpha < 2 * M_PI; alpha += M_PI / 3.) {
            glVertex2d(cos(alpha), sin(alpha));
        }
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    {
        glColor3f(64.f / 255.f, 32.f / 255.f, 0.f / 255.f);

        glVertex2d(.0, -.6);
        glColor3f(192 / 255.f, 192.f / 255.f, 0.f / 255.f);

        glVertex2d(cos(M_PI / 3), sin(M_PI / 3));
        glVertex2d(cos(2 * M_PI / 3), sin(2 * M_PI / 3));
    }
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(63/255.f, 112.f/255.f, 225.f/255.f);
    glBegin(GL_LINE_LOOP);
    {
        for (double alpha = 0; alpha < 2 * M_PI; alpha += M_PI / 3.) {
            glVertex2d(cos(alpha), sin(alpha));
        }
    }
    glEnd();

    glPopMatrix();
}

void gl_robot::set_position(position_t position) {
    m_x = position.x;
    m_y = position.y;
    m_rotation = position.rot;
}
