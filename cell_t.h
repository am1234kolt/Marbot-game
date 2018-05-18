
#ifndef ASSIGNMENT_05_CELL_T_H
#define ASSIGNMENT_05_CELL_T_H

#include <ostream>

enum class cell_t {
    None = -1,
    Wall = 0,
    Path,
    Route,
    Mineral
};

inline bool is_mineral(cell_t& cell) { return cell == cell_t::Mineral; }
inline bool is_path(cell_t& cell) { return cell == cell_t::Path; }
inline bool is_wall(cell_t& cell) { return cell == cell_t::Wall; }
inline bool is_valid(cell_t& cell) { return cell != cell_t::None; }
inline bool is_invalid(cell_t& cell) {return cell == cell_t::None; }

inline std::ostream& operator<<(std::ostream& out, const cell_t& cell){
    out << "cell_t::";
    switch(cell){
        case cell_t::None:
            out << "None";
            break;
        case cell_t::Wall:
            out << "Wall";
            break;
        case cell_t::Path:
            out << "Path";
            break;
        case cell_t::Route:
            out << "Route";
            break;
        case cell_t::Mineral:
            out << "Mineral";
            break;
    }
    return out;
}

inline std::string to_string(const cell_t& cell){
    switch(cell){
        case cell_t::None:
            return  "cell_t::None";
        case cell_t::Wall:
            return "cell_t::Wall";
        case cell_t::Path:
            return "cell_t::Path";
        case cell_t::Route:
            return "cell_t::Route";
        case cell_t::Mineral:
            return "cell_t::Mineral";
    }
}

#endif
