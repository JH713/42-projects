#include "Span.hpp"

Span::Span() :n(0), count(0) {}
Span::Span(unsigned int n) :n(n), count(0) {}
Span::~Span() {}
Span::Span(const Span &copy) :n(copy.n), count(copy.count), v(copy.v) {} 
Span& Span::operator=(const Span &ref) {
	n = ref.n;
	count = ref.count;
	v = ref.v;
	return (*this);
}

void Span::addNumber(int num) {
	if (count < n) {
		v.push_back(num);
		count++;
	}
	else throw ContainerOverflowException();
}

unsigned int Span::shortestSpan() {
	if (count <= 1) throw SpanCantFoundException();
	std::sort(v.begin(), v.end());
	unsigned int min = UINT_MAX;
	int prev = v.front(); 
	for (std::vector<int>::iterator it = v.begin() + 1; it != v.end(); it++) {
		unsigned int temp = *it - prev;
		min = std::min(min, temp);
		prev = *it;
	}
	return min;
}

unsigned int Span::longestSpan() {
	if (count <= 1) throw SpanCantFoundException();
	std::sort(v.begin(), v.end());
	return *(v.end() - 1) - *(v.begin());
}

const char *Span::ContainerOverflowException::what() const throw()
{ return "Container Overflow!"; }

const char *Span::SpanCantFoundException::what() const throw()
{ return "Span can't found!"; }