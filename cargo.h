

#ifndef CARGO_H
#define CARGO_H

#include <unordered_map>
#include <vector>
#include "mineral.h"


class cargo {
public:

    explicit cargo(int capacity); //ctor taking in the capacity

    bool operator+=(mineral min); //addition operator for adding the minerals

    cargo& operator<<(const std::string& str); //stream operator for adding minerals in the old string format

    explicit operator bool();   // returns the negated bad flag
    bool operator!();           // returns the bad flag
    void reset();               // resets the bad flag

    //returns the amount of a specified mineral (or 0 if a mineral with given code not in cargo)
    int operator[](char code);

    // prints the string representation of all the stored minerals to the output stream
    friend std::ostream& operator<<(std::ostream& out, const cargo& c);
    std::vector <mineral> minerals;
    int count() const; //return the total count of all minerals stored

private:
    int m_capacity; //cargo capacity
    bool m_bad;     //bad flag for stream << operations
    //this class needs a data member to actually hold the minerals!
};


#endif
