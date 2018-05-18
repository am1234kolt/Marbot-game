//
// Created by Saxion on 07/12/2017.
//

#ifndef ASSIGNMENT_04_GL_OBJECT_H
#define ASSIGNMENT_04_GL_OBJECT_H

#include "GLFW/glfw3.h"


class gl_object {
public:
    virtual void render() = 0;
    virtual void set_scale(GLfloat scale) {m_scale = scale; }
    virtual GLfloat get_scale() {return m_scale; }
private:
    GLfloat m_scale;
};

#endif //ASSIGNMENT_04_GL_OBJECT_H
