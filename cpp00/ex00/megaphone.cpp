#include <iostream>
#include <string>
#include <algorithm>

static void	Megaphone(std::string str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			Megaphone(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}

static void	Megaphone(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str;
}
