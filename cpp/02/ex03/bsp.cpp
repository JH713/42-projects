#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point d1(b - a);
	Point d2(c - a);
	Point p(point - a);

	if (d2.getX().getRawBits() != 0 &&\
		d2.getY().getRawBits() != 0 &&\
	 	d1.getX() / d2.getX() == d1.getY() / d2.getY())
		return (false);
	if (d2.getX().getRawBits() == 0 && d1.getX().getRawBits() == 0)
		return (false);
	if (d2.getY().getRawBits() == 0 && d1.getY().getRawBits() == 0)
		return (false);
	if (d1.getX().getRawBits() == 0 && d1.getY().getRawBits() == 0)
		return (false);
	if (d2.getX().getRawBits() == 0 && d2.getY().getRawBits() == 0)
		return (false);
	float t1, t2;
	if (d1.getX().getRawBits() == 0)
	{
		t2 = p.getX().toFloat() / d2.getX().toFloat();
	}
	else
	{
		float a = (d2.getY() - (d2.getX() * d1.getY() / d1.getX())).toFloat();
		t2 = (p.getY() - (p.getX() * d1.getY() / d1.getX())).toFloat() / a; 
	}
	t1 = (p.getY().toFloat() - t2 * d2.getY().toFloat()) / d1.getY().toFloat();
	if (t1 <= 0 || t1 >= 1 || t2 <= 0 || t2 >= 1)
		return (false);
	if (t1 + t2 >= 1)
		return (false);
	return (true);
}