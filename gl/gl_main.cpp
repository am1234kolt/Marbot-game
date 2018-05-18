//
// Created by Saxion on 06/12/2017.
//

#include "gl_main.h"
#include "GLFW/glfw3.h"

#include <stdexcept>

gl_main::gl_main(int width, int height, int board_size, std::string title):
m_window(nullptr),
m_board_size(board_size),
m_initialized{false},
m_key_pressed_handler{}
{
    if (!glfwInit()){
        throw std::runtime_error("Failed to initialize OpenGL driver.");
    }

    m_initialized = true;

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    auto c_title{title.c_str()};
    m_window = glfwCreateWindow(width, height, c_title, NULL, NULL);

    if (!m_window) {
        throw std::runtime_error("Failed to vreate OpenGL window.");
    }

    glfwSetWindowUserPointer(m_window, this);

    auto key_func = [](GLFWwindow* window, int key, int scancode, int action, int mods){
        static_cast<gl_main*>(glfwGetWindowUserPointer(window))->key_callback(window, key, scancode, action, mods);
    };

    glfwSetKeyCallback(m_window, key_func);

    glfwMakeContextCurrent(m_window);

    glfwSwapInterval(1);

    glfwSetTime(0.0);
}


gl_main::~gl_main() {
    if (m_window){
        glfwDestroyWindow(m_window);
    }

    if (m_initialized){
        glfwTerminate();
        m_initialized = false;
    }

}

void gl_main::add_object(std::weak_ptr<gl_object> obj) {
    m_objects.push_back(std::move(obj));
}


bool gl_main::render() {

    if (!glfwWindowShouldClose(m_window))
    {
        // KSet up view and projection
        int width, height;
        glfwGetFramebufferSize(m_window, &width, &height);
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, m_board_size, 0, m_board_size, -10, 10);

        // back to drawing
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //clear screen
        glClear(GL_COLOR_BUFFER_BIT);

        glTranslated(10.f, 10.f, 0);

        //render all the objects in the queue
        for (auto& ptr : m_objects){
            if (auto p_locked = ptr.lock()){
                p_locked->render();
            }
        }

        glfwSwapBuffers(m_window);
        glfwPollEvents();

        return true;
    }

    return false;
}

void gl_main::key_callback(GLFWwindow *window, int key, int scancode __attribute__((unused)), int action, int mods __attribute__((unused))) {
    if (action == GLFW_PRESS){
        if (m_key_pressed_handler){
            m_key_pressed_handler(key);
        }
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

}

void gl_main::set_key_pressed_handler(std::function<void(int)> handler) {
    m_key_pressed_handler = std::move(handler);
}

void gl_main::set_clear_color(double r, double g, double b, double alpha=1.) {
    glClearColor(r, g, b, alpha);
}
