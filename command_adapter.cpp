

#include "command_adapter.h"
#include "mineral_probe.h"

#include "GLFW/glfw3.h"

command_adapter::command_adapter(const std::weak_ptr<mineral_probe>& probe) :
        m_wp_probe{probe},
        m_cp{"LEFT", "RIGHT", "FORWARD", "STOP", "PROBE", "RESUME", "DISINTEGRATE"},
        m_move_finished_callback{},
        m_orient{direction_t::North},
        m_position{},
        m_x_start{0}, m_x_goal{0},
        m_animation{},
        m_ammo_count{3}

{
    m_cp.set_func_check_busy(std::bind(&command_adapter::busy, this));
    m_cp.set_func_send_command(std::bind(&command_adapter::operator<<, this, std::placeholders::_1));
}

command_processor &command_adapter::get_command_processor() {
    return m_cp;
}

bool command_adapter::operator<<(const std::string &command) {
    if (!busy()) {
            if (command == "LEFT"){
                turn_left();
            }
            else if (command == "RIGHT"){
                turn_right();
            }
            else if (command == "FORWARD"){
                auto next_cell {next_if_forward()};
                if (next_cell.x != -1){
                    if (m_func_is_path){
                        if (m_func_is_path(next_cell.x, next_cell.y)){
                            move_forward();
                        }
                    }
                    else{
                        move_forward();
                    }
                }
            }
            else if (command == "DISINTEGRATE"){
                disintegrate();
            }
            else if (auto probe = m_wp_probe.lock()) {
                //forward everything else to the probe
                probe->process(command);
            }
            return true;
    }
    return false;
}

bool command_adapter::busy() const {
    return m_animation.active();
}

position_t command_adapter::position() const{
    return m_position;
}

void command_adapter::set_move_finished_clbk(const std::function<void()> &clbk) {
    m_move_finished_callback = clbk;
}

void command_adapter::set_is_path_func(const std::function<bool(int, int)> &func) {
    m_func_is_path = func;
}

void command_adapter::set_remove_obstacle_func(const std::function<bool(int, int)> & func) {
    m_func_remove_obstacle = func;
}

bool command_adapter::Animation::update() {
    if (active()) {
        double tx = glfwGetTime();
        if (tx > (t0 + duration)) {
            position = goal;
            stop();
        } else if (kind == animation_type::Translation) {
            auto fraction{(tx - t0) / duration};
            position.x = start.x + fraction * (goal.x - start.x);
            position.y = start.y + fraction * (goal.y - start.y);
            position.rot = goal.rot;
        } else if (kind == animation_type::Rotation) {
            auto fraction{(tx - t0) / duration};
            position.rot = start.rot + fraction * (goal.rot - start.rot);
            position.x = goal.x;
            position.y = goal.y;
        }
        return true;
    }
    return false;
}

bool command_adapter::update() {
    auto updated = m_animation.update();

    if (updated){
        m_position = m_animation.position;
    }

    if (updated && !m_animation.active()){
        if (m_move_finished_callback){
            m_move_finished_callback();
        }

        if (auto probe = m_wp_probe.lock()){
            probe->set_position(m_position.x, m_position.y);
        }
    }
    return updated;
}

void command_adapter::turn_left() {
    if (!m_animation) {
        m_animation.kind = animation_type::Rotation;
        m_animation.t0 = glfwGetTime();
        m_animation.duration = 0.5;
        m_animation.start = m_position;
        m_animation.goal = m_position;
        m_animation.goal.rot = m_position.rot + 90.;
        auto new_orient = (static_cast<int>(m_orient) - 1);
        if (new_orient < 0) new_orient += 4;
        m_orient = static_cast<direction_t>(new_orient);
    }
}

void command_adapter::turn_right() {
    if (!m_animation){
        m_animation.kind = animation_type::Rotation;
        m_animation.t0 = glfwGetTime();
        m_animation.duration = 0.5;
        m_animation.start = m_position;
        m_animation.goal = m_position;
        m_animation.goal.rot = m_position.rot - 90.;
        m_orient = static_cast<direction_t>(( static_cast<int>(m_orient) + 1) % 4);
    }
}

void command_adapter::move_forward() {
    if (!m_animation) {
        m_animation.kind = animation_type::Translation;
        m_animation.t0 = glfwGetTime();
        m_animation.duration = 0.7;
        m_animation.start = m_position;
        m_animation.goal = m_position;
        switch (m_orient) {
            case direction_t::North:
                m_animation.goal.y += 1;
                break;
            case direction_t::South:
                m_animation.goal.y -= 1;
                break;
            case direction_t::West:
                m_animation.goal.x -= 1;
                break;
            case direction_t::East:
                m_animation.goal.x += 1;
                break;
        }
    }
}

void command_adapter::disintegrate() {

    if (!m_ammo_count) return;

    //determine the orientation
    auto orient { from_rotation(m_animation.position.rot) };

    auto pos{position()};
    switch (orient) {
        case direction_t::North:
            pos.y += 1;
            break;
        case direction_t::South:
            pos.y -= 1;
            break;
        case direction_t::West:
            pos.x -= 1;
            break;
        case direction_t::East:
            pos.x += 1;
            break;
    }

    if (m_func_remove_obstacle){
        if (m_func_remove_obstacle(pos.x, pos.y)){
            m_ammo_count--;
        }
    }
}

position_t command_adapter::next_if_forward() const {
    if (!m_animation) {
        position_t result = m_position;
        switch (m_orient) {
            case direction_t::North:
                result.y = result.y + 1;
                break;
            case direction_t::South:
                result.y = result.y - 1;
                break;
            case direction_t::West:
                result.x = result.x - 1;
                break;
            case direction_t::East:
                result.x = result.x + 1;
                break;
        }
        return result;
    }
    return position_t(-1, -1);
}



void command_adapter::reset(int start_x, int goal_x) {
    m_x_start = start_x;
    m_x_goal = goal_x;
    m_position.x = start_x;
    m_position.y = 0;
    m_orient = direction_t::North;
    m_position.rot = 7200+90. - 90.* static_cast<int>(m_orient);
    m_animation.stop();
}
