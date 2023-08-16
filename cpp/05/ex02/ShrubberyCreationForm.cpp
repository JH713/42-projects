#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation Form", 145, 137), target("") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("Shrubbery Creation Form", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
	: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), target(copy.target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	executeCheck(executor);
	std::string filename = target + "_shrubbery";
	std::ofstream output(filename);
	if (output.fail())
	{
		std::cerr << "Error: Failed to open input file."<<std::endl;
		exit(1);
	}
	output << "           *             ,";
	output << '\n' << "                       _/^\\_";
	output << '\n' << "                      <     >";
	output << '\n' << "     *                 /.-.\\         *";
	output << '\n' << "              *        `/&\\`                   *";
	output << '\n' << "                      ,@.*;@,";
	output << '\n' << "                     /_o.I %_\\    *";
	output << '\n' << "        *           (`'--:o(_@;";
	output << '\n' << "                   /`;--.,__ `')             *";
	output << '\n' << "                  ;@`o %% O,*`'`&\\";
	output << '\n' << "            *    (`'--)_@ ;o %'()\\      *";
	output << '\n' << "                 /`;--._`''--._O'@;";
	output << '\n' << "                /&*,()~o`;-.,_ `""`)";
	output << '\n' << "     *          /`,@ ;+& () o*`;-';\\";
	output << '\n' << "               (`""--.,_0 +% @' &()\\";
	output << '\n' << "               /-.,_    ``''--....-'`)  *";
	output << '\n' << "          *    /@%%;o`:;'--,.__   __.'\\";
	output << '\n' << "              ;*,&(); @ % &^;~`\"`o;@();         *";
	output << '\n' << "              /(); o^~; & ().o@*&`;&%%O\\";
	output << '\n' << "              `\"=\"==\"\"==,,,.,=\"==\"===\"`";
	output << '\n' << "           __.----.(\\-''#####---...___...-----._";
	output << '\n' << "         '`         \\)_`\"\"\"\"\"`";
	output << '\n' << "                 .--' ')";
	output << '\n' << "               o(  )_-\\";
	output << '\n' << "                 `\"\"\"` `";
	output.close();
}

std::string ShrubberyCreationForm::getTarget() const 
{ return (target); }