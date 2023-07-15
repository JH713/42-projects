#include "Point.hpp"

int main( void ) {
	Point a(-2, -2);
	Point b(3, 0);
	Point c(0, 4);
	Point p(0, 0);

	bool result = bsp(a, b, c, p);
	if (result == true)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
}