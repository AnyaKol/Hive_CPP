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

// Destructor
PhoneBook::~PhoneBook(void) {}

void	PhoneBook::add(void) {
	if (this->count == 8)
		this->count = 0;
	this->contacts[this->count].create();
	this->count++;
	if (this->max_count < 8)
		this->max_count++;
}

void	PhoneBook::search(void) {
	std::string	input;
	int			index;

	PhoneBook::print_table();
	std::cout << "Please enter index of contact:" << std::endl;
	std::cin >> input;
	if (input.empty()) {
		std::cout << "No input." << std::endl << std::endl;
		return ;
	}
	try {
		index = std::stoi(input);
	}
	catch (const std::invalid_argument & e) {
		std::cout << "Invalid input: Expected number." << std::endl << std::endl;
		return ;
	}
	catch (const std::out_of_range & e) {
		std::cout << "Invalid input: Number out of range." << std::endl << std::endl;
		return ;
	}
	if (index < 1 || index > 8) {
		std::cout << "Number out of range. Expected number in range [1, 8]." << std::endl << std::endl;
		return ;
	}
	if (index > this->max_count) {
		std::cout << "No contact with this index." << std::endl << std::endl;
		return ;
	}
	this->contacts[index - 1].print_contact();
}

void	PhoneBook::print_table(void) {
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|"
		<< print_content("Index") << "|"
		<< print_content("First name") << "|" 
		<< print_content("Last name") << "|" 
		<< print_content("Nickname") << "|"
		<< std::endl;
	std::cout << "_____________________________________________" << std::endl;
	for (int i = 0; i < this->max_count; i++) {
		std::cout << "|"
			<< this->print_content(std::to_string(i + 1)) << "|"
			<< this->print_content(this->contacts[i].firstName) << "|" 
			<< this->print_content(this->contacts[i].lastName) << "|" 
			<< this->print_content(this->contacts[i].nickname) << "|"
			<< std::endl;
		std::cout << "_____________________________________________" << std::endl;
	}
	std::cout << std::endl;
}

std::string	PhoneBook::print_content(std::string str) {
	std::string	content;

	if (str.empty())
		return "";
	if (str.length() <= 10)
		content = std::string(10 - str.length(), ' ') + str;
	else
		content =  str.substr(0, 9) + ".";
	return (content);
}
