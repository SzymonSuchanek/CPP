#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <climits>
# include <cstdlib>
# include <ctime>  

class RPN {
	
private:

	unsigned int _N;
	std::vector<int> _container;

public:

	RPN();
	RPN(unsigned int N);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	virtual ~RPN();

	class NoRPNException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class ContainerFullException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

	void addNumber(int value);
	int shortestRPN() const;
	int	longestRPN() const;

	template <typename T>
	void addNumbers(T begin, T end) {
		size_t distance = std::distance(begin, end);
		if (_container.size() + distance > _N)
			throw ContainerFullException();
		_container.insert(_container.end(), begin, end);
	}

};

#endif
