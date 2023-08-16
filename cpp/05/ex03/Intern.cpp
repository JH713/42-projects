#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &copy) { (void)copy; }
Intern& Intern::operator=(const Intern &ref) 
{
	(void) ref; 
	return (*this); 
}
Intern::~Intern() {}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form *form;

	std::string formName[3] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	Form *(Intern::*f[3])(std::string);
	f[0] = &Intern::makeSCF;
	f[1] = &Intern::makeRRF;
	f[2] = &Intern::makePPF;
		for (int i = 0; i < 3; ++i)
		{
			if (name == formName[i])
			{
				form = (this->*f[i])(target);
				std::cout << "Intern creates "<< name << ' '<< target << '\n';
				return (form);
			}
		}
		throw FormNotFoundException();
}

Form *Intern::makeSCF(std::string target)
{
	Form * scf = new ShrubberyCreationForm(target);
	return (scf);
}


Form *Intern::makeRRF(std::string target)
{
	Form * rrf = new RobotomyRequestForm(target);
	return (rrf);
}

Form *Intern::makePPF(std::string target)
{
	Form * ppf = new PresidentialPardonForm(target);
	return (ppf);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "The specified form does not exist.";
}