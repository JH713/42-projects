#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("A", 1);
		Bureaucrat B("B", 100);

		Form form1("form1", 10, 5);
		std::cout<<form1;
		// Form form2("form2", 0, 10);
		// Form form3("form3", 151, 10);

		B.signForm(form1);
		A.signForm(form1);
		std::cout<<form1;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout<<"Grade is too high!"<<std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout<<"Grade is too low!"<<std::endl;
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cout<<"Grade is too high!"<<std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout<<"Grade is too low!"<<std::endl;
	}
	return 0;
}