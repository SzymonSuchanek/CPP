#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(const Span &other) : _size(other._size), _container(other._container) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_size = other._size;
		_container = other._container;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_container.size() >= _size) {
        throw std::overflow_error("Container cannot have any more elements.");
    }
    _container.push_back(value);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_container.size() > _size)
		throw std::overflow_error("Container cannot have any more elements.");
	_container.insert(_container.end(), begin, end);
}

int Span::shortestSpan() const {
	if (this->_container.size() <= 1) {
		throw std::logic_error("Not enough elements to find a span.");
	}

	std::vector<int> sorted = this->_container;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t  i = 1; i < sorted.size(); i++) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

int	Span::longestSpan() const {
	if (this->_container.size() <= 1) {
		throw std::logic_error("Not enough elements to find a span.");
	}

	std::vector<int>::const_iterator minIt = std::min_element(_container.begin(), _container.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_container.begin(), _container.end());

	return std::abs(*minIt - *maxIt);
}
