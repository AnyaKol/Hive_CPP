/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:28:00 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/11 18:34:11 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook myPhoneBook;
	std::string command;

	std::cout << "Welcome to PhoneBook!" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "ADD - to add new contact to phone book" << std::endl;
	std::cout << "SEARCH - to search for contact in phone book" << std::endl;
	std::cout << "EXIT - to exit" << std::endl << std::endl;
	while (1) {
		std::cout << "Please enter command:" << std::endl;
		std::cin >> command;
		if (command == "ADD")
			myPhoneBook.add();
		else if (command == "SEARCH")
			myPhoneBook.search();
		else if (command == "EXIT")
			break ;
	}
	return 0;
}
