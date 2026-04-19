/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:17:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Default constructor
// Delegating to constructor with parameter
AAnimal::AAnimal(void) : AAnimal("DefaultAnimal") {}

// Constructor with parameter
AAnimal::AAnimal(std::string name) : AAnimal(name, "AAnimal") {}

AAnimal::AAnimal(std::string name, std::string type) {

	this->_type = type;
	this->_name = name;

	this->_announce();
	std::cout << " created." << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) : AAnimal() {
	this->_announce();
	std::cout << " calls copy constructor from ";
	other._announce();
	std::cout << "." << std::endl;

	*this = other;
}

// Copy assignment operator overload
AAnimal&	AAnimal::operator= (const AAnimal& other) {
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
AAnimal::~AAnimal(void) {
	this->_announce();
	std::cout << " ran away~" << std::endl;
}

// AAnimal function
const std::string&	AAnimal::getType(void) const {
	return (this->_type);
}

const std::string&	AAnimal::getName(void) const {
	return (this->_name);
}

void	AAnimal::setName(const std::string& name) {
	this->_name = name;
}

void	AAnimal::makeSound(void) const {
	this->_announce();
	std::cout << " makes some animal sounds." << std::endl;
}

// Helper function
void	AAnimal::_announce(void) const {
	std::cout << this->_type << ":" << this->_name;
}
