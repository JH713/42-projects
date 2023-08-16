#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Shrubbery Creation Form", 25, 5), target("") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: AForm("Shrubbery Creation Form", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
	: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), target(copy.target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	executeCheck(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const 
{ return (target); }