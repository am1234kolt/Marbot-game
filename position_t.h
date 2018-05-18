

#ifndef POSITION_T_H
#define POSITION_T_H

#include <ostream>
#include <cmath>
struct position_t{
    double x;
    double y;
    double rot;

    position_t(): x{0.}, y{0.}, rot{0.} {}
    position_t(double px, double py) : x{px}, y{py}, rot{} {}

    position_t& operator-=(const position_t& other){
        x -= other.x;
        y -= other.y;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const position_t& pos);
};

inline position_t operator-(position_t lhs, position_t rhs){
    lhs -= rhs;
    return lhs;
}

inline auto l2norm(const position_t& a, const position_t& b){
    auto dx = a.x - b.x;
    auto dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}

inline std::ostream &operator<<(std::ostream &out, const position_t &pos) {
    out << "position_t [x= " << pos.x << "; y= " << pos.y << "; rot=" << pos.rot <<"; ]";
    return out;
}

#endif
