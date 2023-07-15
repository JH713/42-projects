#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point& copy) :x(copy.x), y(copy.y) {}

Point& Point::operator=(const Point& ref)
{
	(void)ref;
	return (*this);
}

Point::~Point() {}

Point Point::operator-(const Point& ref) const
{
	Point pnt(this->x.toFloat() - ref.x.toFloat(), this->y.toFloat() - ref.y.toFloat());
	return (pnt);
}

Fixed Point::getX(void) const
{
	return (x);
}

Fixed Point::getY(void) const
{
	return (y);
}