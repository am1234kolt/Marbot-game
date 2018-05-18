

#ifndef COMMAND_ADAPTER_H
#define COMMAND_ADAPTER_H
#include <memory>
#include <stdexcept>
#include <functional>
#include "maze.h"
#include "gl_robot.h"
#include "mineral_probe.h"
#include "command_processor.h"
#include "position_t.h"
#include "direction.h"

class command_adapter {
public:
    command_adapter(const std::weak_ptr<mineral_probe>& probe);
    bool operator<<(const std::string& command);

    bool busy() const;

    bool update();

    position_t position() const;

    void set_move_finished_clbk(const std::function<void()>& clbk);

    void set_is_path_func(const std::function<bool(int, int)>& func);
    void set_remove_obstacle_func(const std::function<bool(int, int)>& func);

    command_processor& get_command_processor();

    direction_t orientation() const { return m_orient; }

    void reset(int start_x, int goal_x);

private:
    std::weak_ptr<mineral_probe>     m_wp_probe;
    command_processor                m_cp;

    std::function<void()> m_move_finished_callback;
    std::function<bool(int, int)> m_func_is_path;
    std::function<bool(int, int)> m_func_remove_obstacle;

    direction_t m_orient;
    position_t m_position;

    int m_x_start, m_x_goal;


    void turn_left();
    void turn_right();
    void move_forward();
    void disintegrate();

    position_t next_if_forward() const;

    enum class animation_type{
        None,
        Translation,
        Rotation
    };

    struct Animation {
        Animation() : kind(animation_type::None) {}

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

    Animation m_animation;
    int m_ammo_count;


};


#endif
