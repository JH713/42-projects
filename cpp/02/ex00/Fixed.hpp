#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
private:
	int fixedNum;
	static const int fracBitNum = 8;
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed& ref);
	~Fixed();
	
	int getRawBits(void) const; 
	void setRawBits(int const raw);
};

#endif