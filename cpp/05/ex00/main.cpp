#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("A", 1);
		// Bureaucrat B("B", 0);
		// Bureaucrat C("C", 151);
		Bureaucrat D("D", 149);

		// A.incrementGrade();

		std::cout<<D;
		D.decrementGrade();
		std::cout<<D;
		// D.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}