#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <algorithm>

class RPN {
	
private:

	std::stack<int> _stack;

public:

	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void calculate(const std::string &expression);
	
};

#endif
