#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void printInt(const T& n) {
    std::cout << n << " ";
}

template <typename T>
void toUpper(T& c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
}

template <typename T, typename Func>
void iter(T& array, size_t len, Func func) {
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

#endif
