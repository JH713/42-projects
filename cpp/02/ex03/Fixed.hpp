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

	bool operator>(const Fixed &ref);
	bool operator<(const Fixed &ref);
	bool operator>=(const Fixed &ref);
	bool operator<=(const Fixed &ref);
	bool operator==(const Fixed &ref);
	bool operator!=(const Fixed &ref);

	Fixed operator+(const Fixed &ref);
	Fixed operator-(const Fixed &ref);
	Fixed operator*(const Fixed &ref);
	Fixed operator/(const Fixed &ref);

	Fixed& operator++(void);
	const Fixed operator++(int);
	Fixed& operator--(void);
	const Fixed operator--(int);

	static Fixed& min(Fixed &ref1, Fixed &ref2);
	static const Fixed& min(const Fixed &ref1, const Fixed &ref2);
	static Fixed& max(Fixed &ref1, Fixed &ref2);
	static const Fixed& max(const Fixed &ref1, const Fixed &ref2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& ref);

#endif