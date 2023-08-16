#include "Form.hpp"

Form::Form() 
	: name(""), isSigned(false), gradeSign(1), gradeExecute(1) {}
Form::Form(std::string name, int gradeSign, int gradeExecute) 
	: name(name), isSigned(false), gradeSign(gradeSign), gradeExecute(gradeExecute) 
{
	if (gradeSign < 1 || gradeExecute < 1)
	{
		GradeTooHighException expn;
		throw expn;
	}
	if (gradeSign > 150 || gradeExecute > 150)
	{
		GradeTooLowException expn;
		throw expn;
	}
}
Form::Form(const Form &copy)
	: name(copy.name), isSigned(copy.isSigned), gradeSign(copy.gradeSign), gradeExecute(copy.gradeExecute) {}
Form& Form::operator=(const Form &ref)
{
	isSigned = ref.isSigned;
	return (*this);
}
Form::~Form() {}

std::string Form::getName() const { return (name); }
bool Form::getIsSigned() const { return (isSigned); }
int Form::getGradeSign() const { return (gradeSign); }
int Form::getGradeExecute() const {return (gradeExecute); }
void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > gradeSign)
	{
		GradeTooLowException expn;
		throw expn;
	}
	isSigned = true;
}

bool Form::executeCheck(Bureaucrat const & executor) const
{
	if (!isSigned)
	{
		UnsignedFormException expn;
		throw expn;
	}
	if (executor.getGrade() > gradeExecute)
	{
		GradeTooLowException expn;
		throw expn;
	}
	return (true);
}

std::ostream& operator<<(std::ostream& os, const Form& ref)
{
	os<<"Form"<<std::endl;
	os<<"Name: "<<ref.getName()<<std::endl;
	os<<"Is signed?: "<<ref.getIsSigned()<<std::endl;
	os<<"Grade required to sign: "<<ref.getGradeSign()<<std::endl;
	os<<"Grade required to execute: "<<ref.getGradeExecute()<<std::endl;
	return os;
}

const char *Form::GradeTooHighException::what() const throw()
{ return "Grade is too high!"; }

const char *Form::GradeTooLowException::what() const throw ()
{ return "Grade is too low!"; }

const char *Form::UnsignedFormException::what() const throw ()
{ return "Form has not been signed!"; }
