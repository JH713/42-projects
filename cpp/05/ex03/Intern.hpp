#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	Form *makeSCF(std::string target);
	Form *makeRRF(std::string target);
	Form *makePPF(std::string target);
public:
	Intern();
	Intern(const Intern &copy);
	Intern& operator=(const Intern &ref);
	~Intern();

	Form *makeForm(std::string name, std::string target);

	class FormNotFoundException : public std::exception 
	{
	public:
		const char *what() const throw();
	};
};

#endif