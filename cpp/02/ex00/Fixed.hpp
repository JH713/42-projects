#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
};

#endif