#include "AForm.hpp"

AForm::AForm() 
	: name(""), isSigned(false), gradeSign(1), gradeExecute(1) {}
AForm::AForm(std::string name, int gradeSign, int gradeExecute) 
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
AForm::AForm(const AForm &copy)
	: name(copy.name), isSigned(copy.isSigned), gradeSign(copy.gradeSign), gradeExecute(copy.gradeExecute) {}
AForm& AForm::operator=(const AForm &ref)
{
	isSigned = ref.isSigned;
	return (*this);
}
AForm::~AForm() {}

std::string AForm::getName() const { return (name); }
bool AForm::getIsSigned() const { return (isSigned); }
int AForm::getGradeSign() const { return (gradeSign); }
int AForm::getGradeExecute() const {return (gradeExecute); }
void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > gradeSign)
	{
		GradeTooLowException expn;
		throw expn;
	}
	isSigned = true;
}

bool AForm::executeCheck(Bureaucrat const & executor) const
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

std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
	os<<"Form"<<std::endl;
	os<<"Name: "<<ref.getName()<<std::endl;
	os<<"Is signed?: "<<ref.getIsSigned()<<std::endl;
	os<<"Grade required to sign: "<<ref.getGradeSign()<<std::endl;
	os<<"Grade required to execute: "<<ref.getGradeExecute()<<std::endl;
	return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{ return "Grade is too high!"; }

const char *AForm::GradeTooLowException::what() const throw ()
{ return "Grade is too low!"; }

const char *AForm::UnsignedFormException::what() const throw ()
{ return "Form has not been signed!"; }
