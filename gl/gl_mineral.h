//
// Created by Saxion on 07/12/2017.
//

#ifndef ASSIGNMENT_04_GL_MINERAL_H
#define ASSIGNMENT_04_GL_MINERAL_H

#include "gl_object.h"

class gl_mineral : public gl_object {
public:
    gl_mineral(GLfloat x, GLfloat y, GLfloat size = 1.f) :
            m_x{x},
            m_y{y},
            m_size{size} {}
public:
    void render() override;

    void set_scale(GLfloat scale) override;

    GLfloat x() const;

    GLfloat y() const;



private:
    GLfloat m_x, m_y, m_size;
    GLfloat m_sx, m_sy, m_ssize;
};


#endif //ASSIGNMENT_04_GL_MINERAL_H
