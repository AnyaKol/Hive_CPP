/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:27:34 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 14:27:38 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
// Delegating to constructor with parameter
WrongAnimal::WrongAnimal(void) : WrongAnimal("DefaultWrongAnimal") {}

// Constructor with parameter
WrongAnimal::WrongAnimal(std::string name) : WrongAnimal(name, "WrongAnimal") {}

WrongAnimal::WrongAnimal(std::string name, std::string type) {

	this->_type = type;
	this->_name = name;

	this->_announce();
	std::cout << " created." << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : WrongAnimal() {
	this->_announce();
	std::cout << " calls copy constructor from ";
	other._announce();
	std::cout << "." << std::endl;

	*this = other;
}

// Copy assignment operator overload
WrongAnimal&	WrongAnimal::operator= (const WrongAnimal& other) {
	this->_announce();
	std::cout << " copies ";
	other._announce();
	std::cout << "." << std::endl;

	if (this != &other) {
		this->_type = other._type;
		this->_name = other._name;
	}

	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void) {
	this->_announce();
	std::cout << " ran away~" << std::endl;
}

// WrongAnimal function
const std::string&	WrongAnimal::getType(void) const {
	return (this->_type);
}

const std::string&	WrongAnimal::getName(void) const {
	return (this->_name);
}

void	WrongAnimal::setName(const std::string& name) {
	this->_name = name;
}

void	WrongAnimal::makeSound(void) const {
	this->_announce();
	std::cout << " makes some Wrong sounds." << std::endl;
}

// Helper function
void	WrongAnimal::_announce(void) const {
	std::cout << this->_type << ":" << this->_name;
}
