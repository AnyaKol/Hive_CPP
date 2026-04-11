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

	while (1) {
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
