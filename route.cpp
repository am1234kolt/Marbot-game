

#include "route.h"

#include <chrono>
#include <sstream>
#include <iostream>
route::route():
        m_route{},
        m_error{false},
        m_next_index{0},
        m_generator{static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) },
        m_distro{}
{

}

route::route(const std::vector<std::pair<int, int>> &path):
route{}
{
    translate(path);
}

int route::size() const {
    return static_cast<int>(m_route.size());
}

void route::reset() {
    m_error = false;
    m_next_index = 0;
}

bool route::hasNext() const {
    return m_next_index < static_cast<int>(m_route.size());
}

std::string route::getNext() {
    auto str {m_route[m_next_index]};
    if (!inject_error(str)){
        m_next_index++;
    }
    return str;
}

route &route::operator>>(std::string &str) {
    if (hasNext()){
        str = getNext();
    }
    else{
        m_error = true;
    }
    return *this;
}



route::operator bool() const {
    return !m_error;
}

bool route::operator!() const {
    return m_error;
}

void route::translate(const std::vector<std::pair<int, int>> &path) {
    auto orientation{0}; //0=N, 1 = E, 2 = S, 3 = W
    auto count = 1;
    auto previous = path.front();
    for (auto next: path) {
        if (previous.first != next.first || previous.second != next.second) {

            auto ud = next.second - previous.second;
            auto lr = next.first - previous.first;

            auto next_orientation{orientation};
            if (ud != 0) next_orientation = ud == 1 ?  0 : 2;
            else if (lr != 0) next_orientation = lr == 1 ?  1 : 3;
            auto rotation = next_orientation - orientation;
            if (rotation == 3) rotation = -1;
            else if (rotation == -3) rotation = 1;
            std::ostringstream strstr;
            while (rotation != 0) {
                //robot needs to rotate before movinf forward

                if (rotation < 0) {
                    strstr.str("");
                    strstr << count++ << " " << "LEFT";
                    m_route.push_back(strstr.str());
                    rotation++;
                } else if (rotation > 0) {
                    strstr.str("");
                    strstr << count++ << " " << "RIGHT";
                    m_route.push_back(strstr.str());
                    rotation--;
                }

            }
            strstr.str("");
            strstr << count++ << " " << "FORWARD";
            m_route.push_back(strstr.str());
            orientation = next_orientation;
            previous = std::make_pair(next.first, next.second);
        }
    }
}

bool route::inject_error(std::string& str) {
    if (m_distro(m_generator) < 0.2){
        auto genid = [&](auto n){ int _n = 0; while((_n=static_cast<int>(m_distro(m_generator) * 10 - 5))==0){}; return n + _n; };
        std::istringstream strstr{str};
        int count;
        std::string command;
        if (strstr >> count >> command){
            str = std::to_string(genid(count)) + " " + command;
        }
        return true;
    }
    else if (m_distro(m_generator) < 0.2){
        static auto chars = std::string{"!@#$%^&*()<>|0987654321:;|?/.,~`{}[]+=_-"};
        auto genchar = [&](){return chars.at(static_cast<int>(m_distro(m_generator) * chars.size()));};
        std::istringstream strstr{str};
        int count;
        std::string command;
        if (strstr >> count >> command){
            std::ostringstream ostrstr;
            ostrstr << genchar() << genchar() << " " << command;
            str = ostrstr.str();
        }
        return true;
    }
    else{
        return false;
    }
}
