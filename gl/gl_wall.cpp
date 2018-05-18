//
// Created by Saxion on 07/12/2017.
//

#include "gl_wall.h"

void gl_wall::render() {

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_TRIANGLE_STRIP);
    {
        glColor3f(0.3f, 0.3f, 0.0f);
        glVertex2d(m_sx, m_sy);
        glColor3f(211.f / 255.f, 84.f / 255.f, 0.0f);

        glVertex2d(m_sx, m_sy + m_ssize);

        glVertex2d(m_sx + m_ssize, m_sy);
        glColor3f(0.5f, 0.15f, 0.1f);

        glVertex2d(m_sx + m_ssize, m_sy + m_ssize);
    }
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1.0f*get_scale() / 10.f);

    glBegin(GL_LINE_LOOP);
    {
        glColor3f(0.5f, 0.15f, 0.1f);
        glVertex2d(m_sx, m_sy);
        glColor3f(0.7f, 0.7f, 0.7f);
        glVertex2d(m_sx, m_sy + m_ssize);
        glColor3f(0.4f, 0.4f, 0.2f);
        glVertex2d(m_sx + m_ssize, m_sy + m_ssize);
        glVertex2d(m_sx + m_ssize, m_sy);
    }
    glEnd();

}

void gl_wall::set_scale(GLfloat scale) {
    gl_object::set_scale(scale);

    m_sx = m_x * scale;
    m_sy = m_y * scale;
    m_ssize = m_size * scale;
}

GLfloat gl_wall::x() const {
    return m_x;
}

GLfloat gl_wall::y() const {
    return m_y;
}
