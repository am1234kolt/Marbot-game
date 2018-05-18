

#ifndef TUNNEL_MAP_H
#define TUNNEL_MAP_H



#include <string>
#include <vector>
#include "route.h"

class tunnel_map {
public:
    explicit tunnel_map(const std::string& file_name);
    explicit tunnel_map(route& path);
    std::string get_next_command();
    bool has_next_command();

private:
    void read_all(std::ifstream& file);
    std::vector<std::string> m_commands;
    int m_current_step;
};


#endif
