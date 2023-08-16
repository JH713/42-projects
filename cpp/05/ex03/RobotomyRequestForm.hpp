#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Form
{
private:
	std::string target;

	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &ref);
	~RobotomyRequestForm();

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};
#endif