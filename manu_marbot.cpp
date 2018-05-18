
#include "manu_marbot.h"


manu_marbot::manu_marbot(keyboard_reader &k_reader, mineral_probe &probe, command_processor &processor) :
        marbot(probe, processor),
        m_reader{k_reader},
        m_retrieve{false}
{}

bool manu_marbot::do_next_step() {

    if(m_processor.busy())
        return true;
    else{
        auto key =  m_reader.get_key();

        switch(key){

            case keyboard_reader::key::ARROW_LEFT :
                m_processor << m_id++ << "LEFT";
                break;

            case keyboard_reader::key::ARROW_UP :
                m_processor << m_id++ << "FORWARD";
                break;

            case keyboard_reader::key::ARROW_RIGHT:
                m_processor << m_id++ << "RIGHT";
                break;

            case keyboard_reader::key::SPACE:
                m_processor << m_id++ << "DISINTEGRATE";
                break;


            case keyboard_reader::key::KEY_SENSE:
                if(m_probe.sensor_reading() >= 0.5) {
                    m_retrieve = true;
                }
                break;

            case keyboard_reader::key::KEY_PROBE:
                if (m_retrieve) {
                    m_processor << m_id++ << "STOP";
                    m_processor << m_id++ << "PROBE";
                    m_processor << m_id++ << "RESUME";
                    m_cargo += m_probe.retrieve_sample();
                }
                m_retrieve = false;
                break;
        }
        return true;
    }
}
std::string manu_marbot::list_minerals() const {
    std::ostringstream minerals;
    minerals << m_cargo;
    return minerals.str();
}