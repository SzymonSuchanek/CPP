#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <algorithm>

class Span {
	
private:

	std::stack<int> _stack;

public:

	Span();
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void calculate(const std::string &expression);
	
};

#endif
