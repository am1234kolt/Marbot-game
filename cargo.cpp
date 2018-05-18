
#include "cargo.h"



cargo::cargo(int capacity) {
    m_capacity=capacity;
}

bool cargo::operator+=(mineral min) {
    bool add{false};
    if(count()<=m_capacity) {
        for (auto &m : minerals) {
            if (m.code() == min.code()) {
                m += min.amount();
                add = true;
            }
        }
        if (!add) {
            minerals.push_back(std::move(min));
            add = true;
        }
    }
    return add;
}

cargo& cargo::operator<<(const std::string &str) {
    try{
        operator +=(mineral(str));
    }
    catch(...){
        m_bad = true;
    }
    return *this;
}

cargo::operator bool() {
    return !m_bad;
}

bool cargo::operator!() {
    return m_bad;
}

void cargo::reset() {
    m_bad=0;
}

int cargo::operator[](char code) {
    int total={0};
    for (auto& m : minerals){
        if(m.code()==code){
            total =m.amount();
        }
    }

    return total;
}

std::ostream& operator<<(std::ostream& out, const cargo& c) {
    out<<"\"[";
    for (unsigned int i = 0; i <= c.minerals.size(); ++i) {
        if(i==c.minerals.size()){
            out << " "+c.minerals.at(i).to_string()+" ";
        }
        else{
            out << " "+c.minerals.at(i).to_string()+",";
        }
    }
    out<<"]\"";
    return out;
}


int cargo::count() const {
    int m_count = 0;
    for (auto &m : minerals) {
        m_count = m_count + m.amount();
    }
    return m_count;
}