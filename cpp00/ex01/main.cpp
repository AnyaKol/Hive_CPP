#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	PhoneBook myPhoneBook;
	std::string command;

	while (1) {
		cin >> command;
		if (command == "ADD")
			myPhoneBook.add();
		else if (command == "SEARCH")
			myPhoneBook.search();
		else if (command == "EXIT")
			break ;
	}
	return 0;
}
