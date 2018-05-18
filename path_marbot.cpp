
#include <sstream>
#include "path_marbot.h"
path_marbot::path_marbot(const tunnel_map& map, mineral_probe& probe, command_processor& processor):
        marbot(probe,processor),
        m_map{map},
        commands{false}

{

    m_processor << "#RoboExplorers MarBot 3.0";
    m_processor << "#Ready...";

}

//void path_marbot::explore() {
//throw std::runtime_error("Function is deprecated");}


bool path_marbot::do_next_step() {

    if(m_processor.busy()){
        return true;
    }
    else {
        if (!m_was_moving) {
            if (m_map.has_next_command()) {
                m_processor << m_id++ << m_map.get_next_command();
                return  true;
            }
            m_was_moving = true;
        }
        else {

            if (m_probe.sensor_reading() >= 0.5) {
                m_processor << m_id++ << "STOP";
                m_processor << m_id++ << "PROBE";
                m_processor << m_id++ << "RESUME";
                m_cargo += m_probe.retrieve_sample();
            }
            m_was_moving = false;
            return true;
        }
    }

}

std::string path_marbot::list_minerals() const {
    std::ostringstream minerals;
    minerals << m_cargo;
    return minerals.str();
}