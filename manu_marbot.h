

#ifndef MANU_MARBOT_H
#define MANU_MARBOT_H

#include "keyboard_reader.h"
#include "mineral_probe.h"
#include "command_processor.h"
#include "cargo.h"
#include "marbot.h"

class manu_marbot : public marbot{
public:
    manu_marbot(keyboard_reader &reader, mineral_probe &probe, command_processor &processor);
    bool do_next_step();
    std::string list_minerals() const;

private:
    keyboard_reader& m_reader;
    bool m_retrieve;

};
#endif
