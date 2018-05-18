//
// Created by Dawid Zalewski on 13/12/2017.
//

#include "gl_martian.h"
#include "GLFW/glfw3.h"


gl_martian::gl_martian(double size):
    m_x{0.},
    m_y{0.},
    m_rot{0.},
    m_size{size},
    m_last_time{glfwGetTime()}
    {}

void gl_martian::set_position(position_t position) {
        m_x = position.x;
        m_y = position.y;
}

void gl_martian::render() {

    constexpr auto rot_velocity = 240.;
    auto time = glfwGetTime();
    auto d_rotation = (time - m_last_time) * rot_velocity;
    m_rot += d_rotation;
    if (m_rot > 360.) m_rot -= 360.;
    m_last_time = time;

    constexpr double angle_step{2*M_PI / 3.};

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix();

    glScaled(m_size*get_scale(), m_size*get_scale(), 1);
    glTranslated(m_x+.5, m_y+0.5, 0);
    glScaled(0.5, 0.5 , 1);

    glRotated(m_rot, 0, 0, 1);

    glBegin(GL_TRIANGLE_FAN);
    {
        glColor3f(192. / 255.f, 32.f / 255.f, 16.f / 255.f);
        glVertex2d(0, 0);
        glColor3f(156. / 255.f, 16.f / 255.f, 0.f / 255.f);
        for (double alpha = 0; alpha < 2 * M_PI + 0.1; alpha += angle_step) {
            glVertex2d(cos(alpha), sin(alpha));
        }
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    {
        glColor3f(173.f / 255.f, 204.f / 255.f, 20.f / 0.f);

        glVertex2d(.0, .0);
        glColor3f(153 / 255.f, 70.f / 255.f, 61.f / 255.f);

        for (double alpha = 0; alpha < 2 * M_PI + 0.1; alpha += angle_step) {
            glVertex2d(0.5*cos(alpha), 0.5*sin(alpha));
        }


    }
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(225/255.f, 16.f/255.f, 32.f/255.f);
    glBegin(GL_LINE_LOOP);
    {
        for (double alpha = 0; alpha < 2 * M_PI + 0.1; alpha += angle_step) {
            glVertex2d(cos(alpha), sin(alpha));
        }
    }
    glEnd();

    glPopMatrix();
}
