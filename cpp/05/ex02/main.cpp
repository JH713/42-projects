#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("A", 100);
		Bureaucrat B("B", 40);
		Bureaucrat C("C", 1);

		ShrubberyCreationForm form1("one");
		RobotomyRequestForm form2("two");
		PresidentialPardonForm form3("three");

		A.signForm(form1);
		A.signForm(form2);
		B.signForm(form2);
		C.signForm(form3);

		A.executeForm(form1);
		A.executeForm(form2);
		B.executeForm(form2);
		C.executeForm(form3);
	}
	catch(std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}