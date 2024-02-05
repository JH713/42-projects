#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <climits>

class Span 
{
private:
	Span();

	unsigned int n;
	unsigned int count;
	std::vector<int> v;
public:
	Span(unsigned int n);
	~Span();
	Span(const Span &copy);
	Span& operator=(const Span &ref);
	
	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template<class T>
	void addNumbers(T begin, T end) {
		while (begin != end) {
			addNumber(*begin);
			++begin;
		}
	} 

	class ContainerOverflowException : public std::exception 
	{
	public:
		const char *what() const throw();
	};

	class SpanCantFoundException : public std::exception 
	{
	public:
		const char *what() const throw();
	};

};

#endif