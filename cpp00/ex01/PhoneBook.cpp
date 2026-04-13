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
	: _count(0), _maxCount(0) {}

// Destructor
PhoneBook::~PhoneBook(void) {}

void	PhoneBook::add(void) {
	if (this->_count == 8)
		this->_count = 0;
	this->_contacts[this->_count].create();
	this->_count++;
	if (this->_maxCount < 8)
		this->_maxCount++;
}

void	PhoneBook::search(void) {
	std::string	input;
	int			index;

	PhoneBook::_printTable();
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
	if (index > this->_maxCount) {
		std::cout << "No contact with this index." << std::endl << std::endl;
		return ;
	}
	this->_contacts[index - 1].printContact();
}

void	PhoneBook::_printTable(void) {
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|"
		<< _printContent("Index") << "|"
		<< _printContent("First name") << "|" 
		<< _printContent("Last name") << "|" 
		<< _printContent("Nickname") << "|"
		<< std::endl;
	std::cout << "_____________________________________________" << std::endl;
	for (int i = 0; i < this->_maxCount; i++) {
		std::cout << "|"
			<< this->_printContent(std::to_string(i + 1)) << "|"
			<< this->_printContent(this->_contacts[i].firstName) << "|" 
			<< this->_printContent(this->_contacts[i].lastName) << "|" 
			<< this->_printContent(this->_contacts[i].nickname) << "|"
			<< std::endl;
		std::cout << "_____________________________________________" << std::endl;
	}
	std::cout << std::endl;
}

std::string	PhoneBook::_printContent(std::string str) {
	std::string	content;

	if (str.empty())
		return "";
	if (str.length() <= 10)
		content = std::string(10 - str.length(), ' ') + str;
	else
		content =  str.substr(0, 9) + ".";
	return (content);
}
