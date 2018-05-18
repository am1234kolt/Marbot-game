

#ifndef KEYBOARD_READER_H
#define KEYBOARD_READER_H

#include <functional>

class keyboard_reader {
public:
    keyboard_reader();

    enum class key{
        NO_KEY = 0,
        ESC,
        ARROW_LEFT,
        ARROW_RIGHT,
        ARROW_UP,
        SPACE,
        ENTER,
        KEY_SENSE,
        KEY_PROBE
    };

    key get_key();
    operator key();

    std::function<void(int)> get_key_pressed_handler();

private:
    key m_last_key;

    void key_pressed_handler(int key_code);

};


#endif
