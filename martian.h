

#ifndef MARTIAN_H
#define MARTIAN_H

#include <vector>
#include <functional>
#include "position_t.h"
#include "direction.h"

class martian {
public:

    martian(double x, double y);
    bool busy() const;
    bool update(const position_t& pos);
    position_t position() const;

    void set_is_path_func(const std::function<bool(int, int)>& func);

private:

    enum class animation_type{
        None,
        Translation
    };

    struct animation_t {
        animation_t() :
                kind(animation_type::None),
                t0{0},
                duration{0}
        {}

        animation_type kind;
        double t0;
        double duration;

        position_t start, goal;

        position_t position;

        bool active() const {return kind != animation_type::None; }
        operator bool() const{ return active(); }
        bool operator!() const { return !active(); }

        void stop() { kind = animation_type::None; }

        //returns true on animation finished
        bool update();
    };

    animation_t m_animation;
    std::function<bool(int, int)> m_func_is_path;

    std::vector<position_t> generate_options(const position_t& pos);
};


#endif
