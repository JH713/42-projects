#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl harl;

	if(argc != 2)
	{
		std::cout<<"Error: Invalid number of arguments."<<std::endl;
		return (1);
	}
	harl.complain(argv[1]);
}