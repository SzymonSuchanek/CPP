#include "Base.hpp"

int main() {
    std::srand(std::time(0));

    Base* obj = generate();
    
    std::cout << "Identified using pointer: ";
    identify(obj);

    std::cout << "Identified using reference: ";
    identify(*obj);

    delete obj;
    return 0;
}
