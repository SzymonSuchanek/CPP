#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original Data Address: " << &data << std::endl;
    std::cout << "Deserialized Data Address: " << ptr << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;

    return 0;
}
