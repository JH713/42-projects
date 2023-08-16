#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request Form", 72, 45), target("") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm("Robotomy Request Form", 72, 45), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
	: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), target(copy.target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	executeCheck(executor);
	std::cout << "Vrrrrrrrrrrrrrrrrrrr 🛠️🔨🔩" << std::endl;
	srand(time(0));
	if (rand() % 10 < 5)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomization of " << target << " has failed." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const 
{ return (target); }
