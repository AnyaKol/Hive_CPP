/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:33:53 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/11 18:29:29 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact(void) {}

// Destructor
Contact::~Contact(void) {}

void	Contact::create(void) {
	firstName = _getInput("the first name");
	lastName = _getInput("the last name");
	nickname = _getInput("the nickname");
	phoneNumber = _getInput("the phone number");
	darkestSecret = _getInput("the darkest secret");
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
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl << std::endl;
}
