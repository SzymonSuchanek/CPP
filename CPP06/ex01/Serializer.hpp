#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

struct Data {
    std::string type;
    int value;
};

class Serializer {

private:

    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);

public:
    
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif