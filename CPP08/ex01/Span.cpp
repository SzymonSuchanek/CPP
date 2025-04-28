#include "RPN.hpp"

RPN::RPN() : _N(0) {}

RPN::RPN(unsigned int N) : _N(N) {}

RPN::RPN(const RPN &other) : _N(other._N), _container(other._container) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_N = other._N;
		_container = other._container;
	}
	return *this;
}

RPN::~RPN() {}

const char* RPN::NoRPNException::what() const throw() {
	return "RPN cannot be found.";
}

const char* RPN::ContainerFullException::what() const throw() {
	return "Container cannot have any more elements.";
}

void RPN::addNumber(int value) {
    if (_container.size() >= _N) {
        throw ContainerFullException();
    }
    _container.push_back(value);
}

int RPN::shortestRPN() const {
	if (this->_container.size() <= 1) {
		throw RPN::NoRPNException();
	}

	std::vector<int> sorted = this->_container;
	std::sort(sorted.begin(), sorted.end());

	int shortest = INT_MAX;
	for (size_t  i = 1; i < sorted.size(); ++i) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

int	RPN::longestRPN() const {
	if (this->_container.size() <= 1) {
		throw RPN::NoRPNException();
	}

	std::vector<int>::const_iterator minIt = std::min_element(_container.begin(), _container.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_container.begin(), _container.end());

	return std::abs(*minIt - *maxIt);
}
