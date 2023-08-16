#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeSign;
	const int gradeExecute;

	AForm();

public:
	AForm(std::string name, int gradeSign, int gradeExecute);
	AForm(const AForm &copy);
	AForm& operator=(const AForm &ref);
	virtual ~AForm();

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

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif