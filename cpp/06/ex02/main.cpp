#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream> 

Base *generate(void)
{
	Base *base;
	srand(time(0));
	int random = rand() % 3;
	if (random == 0)
		base = new A();
	else if (random == 1)
		base = new B();
	else
		base = new C();
	return base; 
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "Type: A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "Type: B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*> (p);
	if (c)
	{
		std::cout << "Type: C" << std::endl;
		return ;		
	}
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type: A" << std::endl;
		return ;
	}
	catch(std::bad_cast e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type: B" << std::endl;
		return ;
	}
	catch(std::bad_cast e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type: C" << std::endl;
		return ;
	}
	catch(std::bad_cast e) {}
}

int main(void)
{
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;
} 