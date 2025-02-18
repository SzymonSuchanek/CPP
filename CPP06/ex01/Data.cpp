#include "Data.hpp"

Data::Data() : _name(new char[10]) {
    std::strcpy(_name, "default");
}

Data::Data(const Data& other) : _name(new char[std::strlen(other._name) + 1]) {
    std::strcpy(_name, other._name);
}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        delete[] _name;
        _name = new char[std::strlen(other._name) + 1];
        std::strcpy(_name, other._name);
    }
    return *this;
}

Data::~Data() {
    delete[] _name;
}
