
#ifndef PATH_MARBOT_H
#define PATH_MARBOT_H

#include <string>

#include "tunnel_map.h"
#include "mineral_probe.h"
#include "command_processor.h"
#include "cargo.h"
#include "marbot.h"
class path_marbot : public marbot{

public:

    path_marbot(const tunnel_map &map, mineral_probe &probe, command_processor &processor);
    bool do_next_step();
    std::string list_minerals() const ;
    //[[deprecated]]
   // void explore() ;


private:
    tunnel_map m_map;
    bool commands;
    bool m_was_moving;
};;
#endif
