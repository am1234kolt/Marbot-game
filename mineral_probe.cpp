
#include <string>
#include <iostream>
#include <memory>
#include "mineral_probe.h"
#include "mineral.h"

double mineral_probe::sensor_reading() {
    if (m_func_check){
        if (m_func_check(static_cast<int>(m_x), static_cast<int>(m_y))){
            m_last_prob = 0.5 + 0.5*m_distro(m_generator);
        }
        else {
            m_last_prob = m_distro(m_generator)*0.25;
        }
    }
    else {
        m_last_prob = m_distro(m_generator);
    }
    return m_last_prob;
}

void mineral_probe::process(const std::string &command) {
    static std::string minerals = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (command == m_command){
        if (m_last_prob > 0){

            auto ind = static_cast<int>((1. - m_last_prob) * (minerals.size() - 1));
            auto amount{static_cast<int>(m_last_prob * m_distro(m_generator) * 10) + 1};
            m_sample = std::string(1, minerals[ind]) + " " + std::to_string(amount);

            m_last_prob = 0;
            if (m_func_probed){
                m_func_probed(static_cast<int>(m_x), static_cast<int>(m_y));
            }
        }
    }
}

mineral mineral_probe::retrieve_sample() {
    mineral result{m_sample};
    m_sample.clear();
    return result;
}
