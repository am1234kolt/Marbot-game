

#include "tunnel_map.h"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>

tunnel_map::tunnel_map(const std::string& file_name):
    m_commands{},
    m_current_step{0}
{
    std::ifstream map{file_name};
    if (!map){
        throw std::runtime_error("Couldn't open file " + file_name);
    }
    read_all(map);
}

tunnel_map::tunnel_map(route& path) :
        m_commands{},
        m_current_step{0}
{
    std::string command;
    auto expected_id{1};
    path.reset();
    while(path >> command){
        auto wrapped = std::istringstream(command);
        int id;
        std::string text;
        // split the command into id and text
        if(wrapped >> id >> text) {
            if (text == "LEFT" || text == "RIGHT" || text == "FORWARD") {
                if (expected_id == id) {
                    expected_id++;
                    // if splitting went ok, add to commands
                    m_commands.push_back(text);

                }
            }
        }
    }
}

std::string tunnel_map::get_next_command() {
    if (m_current_step >= m_commands.size())
        throw std::out_of_range("No more commands in tunnel_map.");
    return m_commands[m_current_step++];
}

bool tunnel_map::has_next_command() {
    return m_current_step < static_cast<int>(m_commands.size());
}

void tunnel_map::read_all(std::ifstream& file) {
    // static variable that holds the file input stream
    std::string command;
    auto expected_id{1};
    // if reading a command from file was successful
    while (std::getline(file, command)){
        // create a string stream wrapper to split into id and command's text
        auto wrapped = std::istringstream(command);
        int id;
        std::string text;
        // split the command into id and text
        if(wrapped >> id >> text) {
            if (text == "LEFT" || text == "RIGHT" || text == "FORWARD") {
                if (expected_id == id) {
                    expected_id++;
                    // if splitting went ok, add to commands
                    m_commands.push_back(text);
                }
            }
        }
    }
}
