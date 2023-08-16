#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string target;

	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ref);
	~ShrubberyCreationForm();

	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

#endif