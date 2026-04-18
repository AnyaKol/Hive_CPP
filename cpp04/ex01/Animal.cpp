/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:17:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
// Delegating to constructor with parameter
Animal::Animal(void) : Animal("DefaultAnimal") {}

// Constructor with parameter
Animal::Animal(std::string name) : Animal(name, "Animal") {}

Animal::Animal(std::string name, std::string type) {

	this->_type = type;
	this->_name = name;

	this->_announce();
	std::cout << " created." << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : Animal() {
	this->_announce();
	std::cout << " calls copy constructor from ";
	other._announce();
	std::cout << "." << std::endl;

	*this = other;
}

// Copy assignment operator overload
Animal&	Animal::operator= (const Animal& other) {
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
Animal::~Animal(void) {
	this->_announce();
	std::cout << " ran away~" << std::endl;
}

// Animal function
const std::string&	Animal::getType(void) const {
	return (this->_type);
}

const std::string&	Animal::getName(void) const {
	return (this->_name);
}

void	Animal::setName(const std::string& name) {
	this->_name = name;
}

void	Animal::makeSound(void) const {
	this->_announce();
	std::cout << " makes some animal sounds." << std::endl;
}

// Helper function
void	Animal::_announce(void) const {
	std::cout << this->_type << ":" << this->_name;
}
