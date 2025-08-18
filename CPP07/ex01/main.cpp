#include <iostream>
#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, len, printInt<const int>);
    std::cout << std::endl;

    char str[] = "hello";
    size_t strLen = sizeof(str) - 1;

    iter(str, strLen, toUpper<char>);
    std::cout << "Modified string: " << str << std::endl;

    return 0;
}
