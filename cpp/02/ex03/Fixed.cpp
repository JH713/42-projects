#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	fixedNum = ref.fixedNum;
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return fixedNum;
}

void Fixed::setRawBits(int const raw)
{
	fixedNum = raw;
}

Fixed::Fixed(const int intNum)
{
	fixedNum = intNum << 8;
}

Fixed::Fixed(const float floatNum)
{
	fixedNum = roundf(floatNum * 256);
}

float Fixed::toFloat(void) const
{
	return ((float) fixedNum / 256.0);
}

int Fixed::toInt(void) const
{
	return (fixedNum >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& ref)
{
	os<<ref.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &ref)
{
	if (fixedNum > ref.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &ref)
{
	if (fixedNum < ref.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &ref)
{
	if (fixedNum >= ref.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &ref)
{
	if (fixedNum <= ref.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed &ref)
{
	if (fixedNum == ref.fixedNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &ref)
{
	if (fixedNum != ref.fixedNum)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed &ref)
{
	Fixed fix((const float) this->toFloat() + ref.toFloat());
	return (fix);
}

Fixed Fixed::operator-(const Fixed &ref)
{
	Fixed fix((const float) this->toFloat() - ref.toFloat());
	return (fix);
}

Fixed Fixed::operator*(const Fixed &ref)
{
	Fixed fix((const float) this->toFloat() * ref.toFloat());
	return (fix);
}

Fixed Fixed::operator/(const Fixed &ref)
{
	Fixed fix((const float) this->toFloat() / ref.toFloat());
	return (fix);
}

Fixed& Fixed::operator++(void)
{
	fixedNum++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed retobj(*this);
	fixedNum++;
	return (retobj);
}

Fixed& Fixed::operator--(void)
{
	fixedNum--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	const Fixed retobj(*this);
	fixedNum--;
	return (retobj);
}

Fixed& Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return (ref1);
	else
		return (ref2);
}
const Fixed& Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.fixedNum < ref2.fixedNum)
		return (ref1);
	else
		return (ref2);
}

Fixed& Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	else
		return (ref2);
}
const Fixed& Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.fixedNum > ref2.fixedNum)
		return (ref1);
	else
		return (ref2);
}