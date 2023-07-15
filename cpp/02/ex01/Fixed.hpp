#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixedNum;
	static const int fracBits = 8;
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed &ref);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int intNum);
	Fixed(const float floatNum);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& ref);

#endif