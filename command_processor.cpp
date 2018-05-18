
#include <iomanip>
#include "command_processor.h"
#include "mineral_probe.h"
#include "command_adapter.h"

command_processor::command_processor(std::ostream &os):
        m_os{os},
        m_allowed_commands{},
 //       m_adaptor{},
        m_good{true},
        m_expected_command_id{1},
        m_command_id{-1},
        m_command_text{}
{ }

command_processor &command_processor::operator<<(const std::string& value) {

   if (!warn() && (value.find_first_not_of("\t\n ") != std::string::npos)) {
       if ((value.front() == '\"' && value.back() == '\"')) {
           //it's a comment, always allowed:
           m_os << "###   " << value.substr(1, value.size() - 1) << "   ###\n";
       } else if (value.front() == '#') {
           //also a comment
           m_os << "###   " << value.substr(1) << "   ###\n";
       }
       else if (m_command_id != -1){
           if ( is_command(value)){
               // a real command
               process();
           }
           else{
               m_os << "ERROR: command processor expected a command to follow the id: " << m_command_id << ". Instead it received: \n" << value << "\n";
               m_command_id = -1;
               m_good = false;
           }
       }
       else if (is_id_command(value)){
           // an id + command
           process();
       }
       else{
           //error bloody error
           m_os << "ERROR: command processor expected a new command id or and id with a command."
                << " Instead it received: \n" << value << "\n";
           m_command_id = -1;
           m_good = false;

       }

   }
    return *this;
}

command_processor &command_processor::operator<<(const char *value) {
    auto str = std::string{value};
    return operator<<(str);
}

command_processor &command_processor::operator<<(int n) {
    if (!warn()){
        if (m_command_id == -1){
            m_command_id = n;
         }
        else{
            m_os << "ERROR: command processor received a new command id: " << n << ". But the command id was already set to: " << m_command_id << ".\n";
            m_good = false;
            m_command_id = -1;
        }
    }
    return *this;
}

bool command_processor::is_id_command(const std::string& str) {
    std::regex num_command_regex(R"(^\s*([0-9]+)\s+([A-Z]{3,})\s*$)");
    std::smatch match;

    const auto n_ncr = 3;

    if (std::regex_match(str, match, num_command_regex)) {
        if (match.size() == n_ncr) {

            if (m_allowed_commands.count(match[2].str()) != 0){
                try{
                    m_command_id = std::stoi(match[1].str());
                    m_command_text = match[2].str();
                    return true;
                }
                catch(const std::invalid_argument&){}
            }
        }
    }
    return false;
}

bool command_processor::is_command(const std::string& str) {
    std::regex command_regex(R"(^\s*([A-Z]{3,})\s*$)");
    std::smatch match;

    const auto n_ncr = 2;
    if (std::regex_match(str, match, command_regex)) {
        if (match.size() == n_ncr) {
            if (m_allowed_commands.count(match[1].str()) != 0) {
                m_command_text = match[1].str();
                return true;
            }
        }
    }
    return false;
}

bool command_processor::warn() const {
    if (!m_good){
        m_os << "ERROR: command processor is in error state. Reset before continuing.\n";
    }
    return !m_good;
}

bool command_processor::process() {
    if (!m_good)
        return false;

    if (busy())
        return false;

    if (m_expected_command_id == m_command_id){
        m_expected_command_id++;
        m_os << "Executing: [ " << std::setw(3) << m_command_id << " : " << m_command_text << " ]\n";

        std::flush(m_os);

        if (m_func_send_command){
            m_func_send_command(m_command_text);
        }

        m_command_id = -1;
    }
    else{
        m_good = false;
        m_os << "ERROR: command processor received a new command id: " << m_command_id << ". But it was expecting a command with id: " << m_expected_command_id << ".\n";
    }

    return m_good;
}

bool command_processor::busy() const {

    if (m_func_check_busy){
        return m_func_check_busy();
    }
    return false;
}

void command_processor::set_func_check_busy(const std::function<bool()> &m_func_check_busy) {
    command_processor::m_func_check_busy = m_func_check_busy;
}

void command_processor::set_func_send_command(const std::function<bool(const std::string &)> &m_func_send_command) {
    command_processor::m_func_send_command = m_func_send_command;
}
