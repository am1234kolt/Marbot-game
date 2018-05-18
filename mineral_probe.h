

#ifndef SENSOR_H
#define SENSOR_H

#include <random>
#include <chrono>
#include <memory>
//#include "command_adapter.h"
#include "mineral.h"
#include "maze.h"
#include <functional>
class mineral_probe {
public:

    using func_check = std::function<bool(int, int)>;
    using func_probed = std::function<void(int, int)>;

    mineral_probe(std::string probing_command, func_check f_check_minerals, func_probed f_probed):
            m_generator{static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) },
            m_distro{},
            m_command{std::move(probing_command)},
            m_last_prob{0.0},
            m_sample{},
            m_func_check{std::move(f_check_minerals)},
            m_func_probed{std::move(f_probed)},
            m_x{0.},
            m_y{0.}
    {

    }


    explicit mineral_probe(std::string probing_command):
            mineral_probe(std::move(probing_command), func_check{}, func_probed{})
    {}



    double sensor_reading();
    mineral retrieve_sample();


private:

    friend class command_adapter;
    void process(const std::string& command);
    void set_position(double x, double y) {m_x = x; m_y = y;}

    std::mt19937 m_generator;
    std::uniform_real_distribution<double> m_distro;
    std::string m_command;
    double m_last_prob;
    std::string m_sample;
    func_check m_func_check;
    func_probed m_func_probed;
    double m_x, m_y;

};


#endif
