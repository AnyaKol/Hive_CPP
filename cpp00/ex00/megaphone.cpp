#include <iostream>

static void	Megaphone(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
			Megaphone(argv[i]);
		std::cout << "\n";
	}
	return 0;
}

static void	Megaphone(char *str)
{
	if (!str)
		return ;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ('a' <= str[i] && str[i] <= 'z')
			std::cout << (char) (str[i] - ('a' - 'A'));
		else
			std::cout << (char) str[i];
	}
}