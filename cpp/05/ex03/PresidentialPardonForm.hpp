#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string target;

	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &ref);
	~PresidentialPardonForm();

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

#endif