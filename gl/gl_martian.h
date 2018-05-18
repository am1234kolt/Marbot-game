//
// Created by Dawid Zalewski on 13/12/2017.
//

#ifndef ASSIGNMENT_05_GL_MARTIAN_H
#define ASSIGNMENT_05_GL_MARTIAN_H


#include "gl_object.h"

#include <utility>
#include <cmath>

#include "../position_t.h"
class gl_martian : public gl_object {
public:

    explicit gl_martian(double size=1.);

    double x() const { return m_x; }
    double y() const { return m_y; }
    std::pair<double, double> position() const { return std::make_pair(m_x, m_y); };

    void set_position(position_t position);
    void render() override;

private:
    double m_x;
    double m_y;
    double m_rot;
    double m_size;
    double m_last_time;
};


#endif //ASSIGNMENT_05_GL_MARTIAN_H
