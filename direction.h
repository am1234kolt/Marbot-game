

#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>

enum class direction_t{
    North = 0,
    East = 1,
    South = 2,
    West = 3
};

inline std::ostream& operator<<(std::ostream& out, const direction_t& d){
    out << "direction_t::";
    switch (d){
        case direction_t::North:
            out << "North";
            break;
        case direction_t::East:
            out << "East";
            break;
        case direction_t::South:
            out << "South";
            break;
        case direction_t::West:
            out << "West";
            break;
    }
    return out;
}

inline std::string to_string(const direction_t& d){
    switch (d){
        case direction_t::North:
            return  "direction_t::North";
        case direction_t::East:
            return "direction_t::East";
        case direction_t::South:
            return "direction_t::South";
        case direction_t::West:
            return "direction_t::West";
    }
}

inline direction_t rotate_left(const direction_t& d){
    return static_cast<direction_t>(((4 + static_cast<int>(d) - 1) % 4));
}

inline direction_t rotate_right(const direction_t& d){
    return static_cast<direction_t>(((4 + static_cast<int>(d) + 1) % 4));
}

inline direction_t reverse(const direction_t& d){
    return static_cast<direction_t>(((4 + static_cast<int>(d) + 2) % 4));
}

inline direction_t from_rotation(double rotation){
    while (rotation < 0.) rotation += 360.;
    while (rotation > 360.) rotation -= 360;
    if (rotation >= 45. && rotation < 135. )
        return direction_t ::North;
    else if (rotation >= 135. && rotation < 225.)
        return direction_t ::West;
    else if (rotation >= 225. && rotation < 315.)
        return direction_t ::South;
    else
        return direction_t :: East;
}

#endif
