#ifndef MARBOT_H
#define MARBOT_H

#include <string>
#include "command_processor.h"
#include "cargo.h"
#include "mineral_probe.h"
#include "tunnel_map.h"


class marbot {
public:

    marbot( mineral_probe &probe, command_processor &processor):
            m_cargo(10),
            m_processor(processor),
            m_probe(probe),
            m_id{1}
    {};

    virtual ~marbot() {} //destructor
    virtual bool do_next_step() =0;
    virtual std::string list_minerals() const =0;
    //virtual void explore()=0;


protected:
    cargo m_cargo;
    command_processor& m_processor;
    mineral_probe& m_probe;
    int m_id;
};
#endif