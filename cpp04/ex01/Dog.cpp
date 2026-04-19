/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:17:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog(void) : Dog("DefaultDog") {}

// Constructor with parameter
Dog::Dog(std::string name) : Animal(name, "Dog") {
	this->_brain = new Brain;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
	this->_brain = new Brain;

	*this->_brain = *other._brain;
}

// Copy assignment operator overload
Dog&	Dog::operator= (const Dog& other){

	this->Animal::operator=(other);

	if (this != &other) {
		*this->_brain = *other._brain;
	}

	return (*this);
}

// Destructor
Dog::~Dog(void) {
	delete this->_brain;
}

// Overridden function
void	Dog::makeSound(void) const {
	this->_announce();
	std::cout << " says: Woof-Woof." << std::endl;
}

// Dog functions
Brain*	Dog::getBrain(void) const {
	return (this->_brain);
}
