#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(float x, float y);
	Point(const Point& copy);
	Point& operator=(const Point& ref);
	~Point();

	Point operator-(const Point& ref) const;
	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif