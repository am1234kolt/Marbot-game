//
// Created by Saxion on 06/12/2017.
//

#ifndef ASSIGNMENT_04_GL_MAIN_H
#define ASSIGNMENT_04_GL_MAIN_H

#include "GLFW/glfw3.h"
#include "gl_object.h"
#include <string>
#include <memory>
#include <vector>
#include <functional>

class gl_main {

public:
    gl_main(int width, int height, int board_size, std::string title);
    bool render();
    void add_object(std::weak_ptr<gl_object> obj);
    ~gl_main();

    void set_key_pressed_handler(std::function<void(int)> handler);

    void set_clear_color(double r, double g, double b, double alpha);
private:

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    GLFWwindow* m_window;
    int m_board_size;
    bool m_initialized;
    std::vector<std::weak_ptr<gl_object>> m_objects;
    std::function<void(int)> m_key_pressed_handler;
};


#endif //ASSIGNMENT_04_GL_MAIN_H
