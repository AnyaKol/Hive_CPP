/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:17:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat(void) : Cat("DefaultCat") {}

// Constructor with parameter
Cat::Cat(std::string name) : Animal(name, "Cat") {
	this->_brain = new Brain;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
	this->_brain = new Brain;

	*this->_brain = *other._brain;
}

// Copy assignment operator overload
Cat&	Cat::operator= (const Cat& other){

	this->Animal::operator=(other);

	if (this != &other) {
		*this->_brain = *other._brain;
	}

	return (*this);
}

// Destructor
Cat::~Cat(void) {
	delete this->_brain;
}

// Overridden function
void	Cat::makeSound(void) const {
	this->_announce();
	std::cout << " says: Meow-Meow, Mrrr." << std::endl;
}

// Cat functions
Brain*	Cat::getBrain(void) const {
	return (this->_brain);
}
