#include <iostream>
#include "iter.hpp"

void printInt(const int& n) {
    std::cout << n << " ";
}

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, len, printInt);
    std::cout << std::endl;

    char str[] = "hello";
    size_t strLen = sizeof(str) - 1;

    iter(str, strLen, toUpper);
    std::cout << "Modified string: " << str << std::endl;

    return 0;
}
