

#include <iostream>
#include "keyboard_reader.h"
#include "GLFW/glfw3.h"

keyboard_reader::keyboard_reader():
        m_last_key{key::NO_KEY}
{}

keyboard_reader::key keyboard_reader::get_key() {
    auto r{m_last_key};
    m_last_key = key::NO_KEY;
    return r;
}

keyboard_reader::operator key() {
    return get_key();
}

void keyboard_reader::key_pressed_handler(int key_code) {

    switch (key_code){
        case GLFW_KEY_ESCAPE:
            m_last_key = key::ESC;
            break;
        case GLFW_KEY_LEFT:
            m_last_key = key::ARROW_LEFT;
            break;
        case GLFW_KEY_RIGHT:
            m_last_key = key::ARROW_RIGHT;
            break;
        case GLFW_KEY_UP:
            m_last_key = key::ARROW_UP;
            break;
        case GLFW_KEY_ENTER:
            m_last_key = key::ENTER;
            break;
        case GLFW_KEY_SPACE:
            m_last_key = key::SPACE;
            break;
        case GLFW_KEY_S:
            m_last_key = key::KEY_SENSE;
            break;
        case GLFW_KEY_X:
            m_last_key = key::KEY_PROBE;
            break;
        default:
            m_last_key = key::NO_KEY;
            break;
    }
}

std::function<void(int)> keyboard_reader::get_key_pressed_handler() {
    return std::bind(&keyboard_reader::key_pressed_handler, this, std::placeholders::_1);
}
