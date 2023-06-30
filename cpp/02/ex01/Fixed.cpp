#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0) 
{
	std::cout<< "Default constructor called" <<std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout<< "Int constructor called" <<std::endl;
	fixedNum = num << 8;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	fixedNum = ref.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;

	return fixedNum;
}

void Fixed::setRawBits(int const raw)
{
	fixedNum = raw;
}