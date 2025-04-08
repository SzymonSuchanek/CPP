#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _container(other._container) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_N = other._N;
		_container = other._container;
	}
	return *this;
}

Span::~Span() {}

const char* Span::NoSpanException::what() const throw() {
	return "Span cannot be found.";
}

const char* Span::ContainerFullException::what() const throw() {
	return "Container cannot have any more elements.";
}

void Span::addNumber(int value) {
    if (_container.size() >= _N) {
        throw ContainerFullException();
    }
    _container.push_back(value);
}

int Span::shortestSpan() const {
	if (this->_container.size() <= 1) {
		throw Span::NoSpanException();
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

int	Span::longestSpan() const {
	if (this->_container.size() <= 1) {
		throw Span::NoSpanException();
	}

	std::vector<int>::const_iterator minIt = std::min_element(_container.begin(), _container.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_container.begin(), _container.end());

	return std::abs(*minIt - *maxIt);
}
