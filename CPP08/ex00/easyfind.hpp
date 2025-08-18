#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>
# include <exception>
# include <iterator>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::out_of_range("Value not found in container.");

	return it;
}

#endif
