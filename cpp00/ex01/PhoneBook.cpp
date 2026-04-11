/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:45:24 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/11 18:48:53 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void)
	: count(0), max_count(0) {}

void	add(void) {
	if (PhoneBook::count == 8) {
		delete PhoneBook::contacts[0];
		PhoneBook::count = 0;
	}
	PhoneBook::contacts[PhoneBook::count] = new Contact;
	PhoneBook::count++;
	if (PhoneBook::max_count < 8)
		PhoneBook::max_count++;
}

void	search(void) {
	std::string	input;
	int			index;

	PhoneBook::print_table();
	std::cin >> input;
	if (!input) {
		std::cout << "No input." << std::endl;
		return ;
	}
	index = stoi(input);
	if (input != to_string(index)) {
		std::cout << "Wrong input. Expected number." << std::endl;
		return ;
	}
	if (index < 1 || index > 8) {
		std::cout << "Number out of range. Expected number in range [1, 8]." << std::endl;
		return ;
	}
	if (index > PhoneBook::max_count) {
		std::cout << "No contact with this index." << std::endl;
		return ;
	}
	PhoneBook::contacts[PhoneBook::index].print_contact();
}

void	print_table(void) {
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|"
		<< print_content("Index") << "|"
		<< print_content("First name") << "|" 
		<< print_content("Last name") << "|" 
		<< print_content("Nickname") << "|"
		<< std::endl;
	std::cout << "_____________________________________________" << std::endl;
	for (int i = 0; i < PhoneBook::max_count; i++) {
		std::cout << "|"
			<< print_content(to_string(i)) << "|"
			<< print_content(PhoneBook::contacts[i].firstName) << "|" 
			<< print_content(PhoneBook::contacts[i].lastName) << "|" 
			<< print_content(PhoneBook::contacts[i].nickname) << "|"
			<< std::endl;
		std::cout << "_____________________________________________" << std::endl;
	}
}

void	print_content(std::string str) {
	if (!str)
		return ;
	if (str.length() <= 10)
		std::cout << std::string(10 - str.length(), ' ') << str;
	else
		std::cout << str.substr(0, 9) << ".";
}
