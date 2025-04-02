#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>
# include <exception>

class NotFoundException : public std::exception {

public:
	virtual const char* what() const throw() {
		return "Value not found in container.";
	}

};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw NotFoundException();

	return it;
}

#endif
