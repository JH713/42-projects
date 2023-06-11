#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout<<"Error: Invalid number of arguments."<<std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string newFilename = filename + ".replace"; 
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream input(filename);
	if (input.fail())
	{
		std::cerr << "Error: Failed to open input file."<<std::endl;
		return (1);
	}
	std::ofstream output(newFilename);
	if (output.fail())
	{
		std::cerr<<"Error: Failed to create output file."<<std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(input, line))
	{
		std::size_t pos = 0;
		while (1)
		{
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
				break ;
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		output<<line;
		if (!input.eof())
			output<<std::endl; 
	}
	
	input.close();
	output.close();
	return (0);
}