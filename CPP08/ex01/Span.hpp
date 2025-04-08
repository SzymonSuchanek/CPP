#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <climits>
# include <cstdlib>
# include <ctime>  

class Span {
	
private:

	unsigned int _N;
	std::vector<int> _container;

public:

	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	virtual ~Span();

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class ContainerFullException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

	void addNumber(int value);
	int shortestSpan() const;
	int	longestSpan() const;

	template <typename T>
	void addNumbers(T begin, T end) {
		size_t distance = std::distance(begin, end);
		if (_container.size() + distance > _N)
			throw ContainerFullException();
		_container.insert(_container.end(), begin, end);
	}

};

#endif
