

#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include <ostream>
#include <iostream>
#include <string>
#include <regex>
#include <unordered_set>


class command_adapter;
class mineral_probe;

struct command_processor
{
    explicit command_processor(std::ostream& os=std::cout);


    command_processor(std::initializer_list<std::string> lst, std::ostream& os=std::cout):
            command_processor{os}
    {
        set_allowed_commands(lst);
    }

    template <typename T>
    command_processor& operator<<(T value){
        if (!warn()) {
            m_os << "ERROR: command processor received unsupported input:\n" << value << "\n";
            m_good = false;
        }
        return *this;
    }

    command_processor& operator<<(const char* value);
    command_processor& operator<<(const std::string& value);
    command_processor& operator<<(int n);

    explicit operator bool() const{
        return m_good && static_cast<bool>(m_os);
    }

    bool operator!() const {
        return !m_good || m_os.operator!();
    }

    bool bad() const { return !m_good || m_os.bad(); }
    bool eof() const { return m_os.eof(); }
    bool fail() const  { return !m_good || m_os.fail(); }
    bool good() const { return m_good && m_os.good(); }

    void reset() {m_good = true; m_command_id = -1; }

    void set_allowed_commands(std::initializer_list<std::string> lst){
        m_allowed_commands.clear();
        m_allowed_commands.insert(lst);
    }

    bool busy() const;

    void set_func_check_busy(const std::function<bool()> &m_func_check_busy);

    void set_func_send_command(const std::function<bool(const std::string &)> &m_func_send_command);

private:
    std::ostream&   m_os;
    std::unordered_set<std::string> m_allowed_commands;
  //  std::weak_ptr<command_adapter>  m_adaptor;
    bool            m_good;
    int             m_expected_command_id;
    int             m_command_id;
    std::string     m_command_text;

    std::function<bool()> m_func_check_busy;
    std::function<bool(const std::string&)> m_func_send_command;

    bool is_id_command(const std::string& str);
    bool is_command(const std::string& str);

    bool warn() const;
    bool process();



    friend class mineral_probe;
};


#endif
