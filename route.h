

#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <string>
#include <random>

class route {
public:
    route();
    route(const std::vector<std::pair<int, int>>& path);


    int size() const;
    void reset();
    bool hasNext() const;

    std::string getNext();


    route& operator>>(std::string& str);

    explicit operator bool() const;
    bool operator!() const;
    void translate(const std::vector<std::pair<int, int>>& path);

private:
    bool inject_error(std::string& str);

    std::vector<std::string> m_route;
    bool m_error;
    int m_next_index;
    std::mt19937 m_generator;
    std::uniform_real_distribution<double> m_distro;



};


#endif
