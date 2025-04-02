#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) { 
	_container.resize(N, 0);
}

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
	if (_container.size() == _container.capacity()) {
		throw Span::ContainerFullException();
	}

	std::vector<int>::iterator it = std::find(_container.begin(), _container.end(), 0);
	if (it != _container.end()) {
        *it = value;
	}
}

int Span::shortestSpan() const {

}

int	Span::longestSpan() const {

}