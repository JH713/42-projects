#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char *argv[])
{
	char ch;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int i = 1;
		while (i < argc)
		{
			for (int j = 0; j < strlen(argv[i]); j++)
			{
				ch = toupper(argv[i][j]);
				std::cout << ch;
			}
			++i;
		}
		std::cout << std::endl;
	}
	return (0);
}