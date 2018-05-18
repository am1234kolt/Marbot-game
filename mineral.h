

#ifndef MINERAL_H
#define MINERAL_H

#include <string>
#include <sstream>
#include <stdexcept>

class mineral {
public:
    //no copying of minerals is possible!
    mineral(const mineral& other) = delete;
    mineral& operator=(const mineral& other) = delete;

    //but moving minerals is ok
    mineral(mineral&& other) = default;
    mineral& operator=(mineral&& other) = default;

    //constructor taking symbol and amount
    mineral(char code, int amount):
            m_code{code},
            m_amount{amount}
    { }

    //constructor building mineral from its string representation (e.g. "A 7")
    mineral(std::string str){
        if (str.empty()){
            m_code = '!';
            m_amount = -1;
        }
        else {
            std::istringstream iss{str};
            if (!(iss >> m_code >> m_amount)) {

                throw std::runtime_error("Error decoding mineral from string: " + str);
            }
        }
    }

    // getters for mineral code and amount
    char code() const { return m_code; }
    int amount() const { return m_amount; }


    //adding minerals
    mineral& operator+=(int count){
        m_amount+= count;
        return *this;
    }

    mineral& operator-=(int count){
        if (m_amount-count < 0)
            throw std::logic_error("Mineral's amount cannot be negative");
        m_amount -= count;
        return *this;
    }

    //simple to_string method
    std::string to_string() const{
        std::string result{m_code};
        return result + " " + std::to_string(m_amount);
    }

private:
    char m_code;
    int m_amount;
};

// stream output operator implemented as free function
inline std::ostream& operator<<(std::ostream& out, const mineral& min){
    return out << min.code() << min.amount();
}

#endif
