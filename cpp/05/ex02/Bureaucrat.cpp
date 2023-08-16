#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) 
{
	if (grade < 1)
	{
		GradeTooHighException expn;
		throw expn;
	}
	if (grade > 150)
	{
		GradeTooLowException expn;
		throw expn;
	}
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) :name(copy.name), grade(copy.grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{ 
	grade = ref.grade; 
	return (*this);
}
Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{ return (name); }

int Bureaucrat::getGrade() const
{ return (grade); }

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
	{
		GradeTooHighException expn;
		throw expn;
	}
	--grade;
}
void Bureaucrat::decrementGrade()
{
	if (grade == 150)
	{
		GradeTooLowException expn;
		throw expn;
	}
	++grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref)
{
	os<<ref.getName()<<", bureaucrat grade "<<ref.getGrade()<<"."<<std::endl;
	return os;
}

void Bureaucrat::signForm(AForm &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout<<name<<" signed "<<form.getName()<<"."<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<name<<" couldn't sign "<<form.getName()<<" because "<<e.what()<<std::endl;
	}
} 

void Bureaucrat::executeForm(AForm const & form)
{
	try 
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << ' ' << form.getTarget() << "." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't executed " << form.getName() << ' ' << form.getTarget() << " because "<< e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{ return "Grade is too high!"; }

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{ return "Grade is too low!"; }