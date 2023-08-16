#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someIntern;
		Form *scf = someIntern.makeForm("Shrubbery Creation Form", "scf");
		Form *rrf = someIntern.makeForm("Robotomy Request Form", "rrf");
		Form *ppf = someIntern.makeForm("Presidential Pardon Form", "ppf");

		Bureaucrat A("A", 5);
		A.signForm(*rrf);
		A.executeForm(*rrf);

		delete scf;
		delete rrf;
		delete ppf;

		Form *wrong = someIntern.makeForm("wrongForm", "target");
		
		A.signForm(*wrong);

		delete wrong;
	}
	catch(std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}