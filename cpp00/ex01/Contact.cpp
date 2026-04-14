/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:33:53 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 15:10:44 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact(void) {}

// Destructor
Contact::~Contact(void) {}

void	Contact::create(void) {
	_firstName = _getInput("the first name");
	_lastName = _getInput("the last name");
	_nickname = _getInput("the nickname");
	_phoneNumber = _getInput("the phone number");
	_darkestSecret = _getInput("the darkest secret");
	std::cout << "Contact added!" << std::endl << std::endl;
}

std::string	Contact::_getInput(std::string field) {
	std::string	input;

	input = "";
	while (input.empty()) {
		std::cout << "Please enter " << field << ":" << std::endl;
		std::cin >> input;
	}
	return (input);
}

void	Contact::printContact(void) {	
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl << std::endl;
}

const std::string	Contact::getFirstName(void) {
	return (this->_firstName);
}

const std::string	Contact::getLastName(void) {
	return (this->_lastName);
}

const std::string	Contact::getNickname(void) {
	return (this->_nickname);
}
