
#include "martian.h"
#include "direction.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include "GLFW/glfw3.h"

constexpr auto k_smart_factor{3};

martian::martian(double x, double y):
    m_animation{},
    m_func_is_path{}
{
    m_animation.position = position_t(x, y);
}

bool martian::busy() const {
    return m_animation.active();
}

bool martian::update(const position_t& pos) {

    m_animation.update();
    if (!m_animation.active()){
        //calculate next move and start animating
        auto options{generate_options(pos)};
        std::random_shuffle(options.begin(), options.end());
        m_animation.t0 = glfwGetTime();
        m_animation.duration = 0.8;
        m_animation.start = position();
        m_animation.goal = options.front();
        m_animation.kind = animation_type::Translation;
    }
    //always force ui update
    return true;
}

position_t martian::position() const {
    return m_animation.position;
}

bool martian::animation_t::update() {
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
        }
        return true;
    }
    return false;
}


std::vector<position_t> martian::generate_options(const position_t& pos) {
    //martians are stupid: they choose randomly the next move with a small preference for the direction where marbot is
    auto dx = pos.x - m_animation.position.x;
    auto dy = pos.y - m_animation.position.y;
    // pref. direction
    std::vector<direction_t> options{direction_t::North, direction_t::North, direction_t::North, direction_t::North};

    if (std::fabs(dy) > std::fabs(dx)){
        if (dy > 0){
            options[0] = direction_t::North;
            options[3] = direction_t::South;
        }
        else{
            options[0] = direction_t::South;
            options[3] = direction_t::North;
        }
        if (dx > 0){
            options[1] = direction_t::East;
            options[2] = direction_t::West;
        }
        else{
            options[1] = direction_t::West;
            options[2] = direction_t::East;
        }

    }
    else{
        if (dx > 0){
            options[0] = direction_t::East;
            options[3] = direction_t::West;
        }
        else{
            options[0] = direction_t::West;
            options[3] = direction_t::East;
        }

        if (dy > 0){
            options[1] = direction_t::North;
            options[2] = direction_t::South;
        }
        else{
            options[1] = direction_t::South;
            options[2] = direction_t::North;
        }
    }

    std::vector<position_t> result;
    auto count{4};
    for (auto& o : options){
        auto _p = position();
        switch (o){
            case direction_t::North:
                _p.y += 1;
                break;
            case direction_t::South:
                _p.y -= 1;
                break;
            case direction_t::West:
                _p.x -= 1;
                break;
            case direction_t::East:
                _p.x += 1;
                break;
        }
        if (!m_func_is_path || m_func_is_path(_p.x, _p.y)){
            auto smart_count{count};
            if (l2norm(pos, position()) < (k_smart_factor*5.)){
                if (count == 4) {smart_count = k_smart_factor * count / 2;}
                else if (count == 3) {smart_count = k_smart_factor * count / 2;}
            }
            for (auto i=0; i < smart_count; ++i){
                result.emplace_back(_p);
            }
        }
        count--;
    }

    return result;
}


void martian::set_is_path_func(const std::function<bool(int, int)> &func) {
    m_func_is_path = func;
}