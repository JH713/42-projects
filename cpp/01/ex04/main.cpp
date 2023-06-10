#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout<<"Error: Invalid number of arguments."<<std::endl;
	}
	std::string filename = argv[1];
	std::string newFilename = filename + ".replace"; 
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream ifs;
	ifs.open(filename);
	std::ofstream ofs;
	ofs.open(newFilename);
}