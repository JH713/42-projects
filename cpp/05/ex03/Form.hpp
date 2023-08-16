#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeSign;
	const int gradeExecute;

	Form();

public:
	Form(std::string name, int gradeSign, int gradeExecute);
	Form(const Form &copy);
	Form& operator=(const Form &ref);
	virtual ~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	void beSigned(Bureaucrat &b);
	bool executeCheck(Bureaucrat const & executor) const;
	
	virtual void execute(Bureaucrat const & executor) const = 0;
	virtual std::string getTarget() const = 0;

	class GradeTooHighException : public std::exception 
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{
	public:
		const char *what() const throw();
	};

	class UnsignedFormException : public std::exception 
	{
	public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& ref);

#endif