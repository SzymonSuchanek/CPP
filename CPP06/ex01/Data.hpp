#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <cstring>

struct Data {

private:
    
    char* _name;

public:

    int value;
    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

};

#endif
