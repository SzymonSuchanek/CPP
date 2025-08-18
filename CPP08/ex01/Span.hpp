#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <climits>
# include <cstdlib>
# include <ctime>
# include <stdexcept> 

class Span {
	
private:

	unsigned int _size;
	std::vector<int> _container;

public:

	Span();
	Span(unsigned int size);
	Span(const Span &other);
	Span &operator=(const Span &other);
	virtual ~Span();

	void addNumber(int value);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan() const;
	int	longestSpan() const;

};

#endif
