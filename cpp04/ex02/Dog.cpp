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
Dog::Dog(void) : AAnimal() {
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "Dog calls default constructor." << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : AAnimal() {
	std::cout << "Dog calls copy constructor." << std::endl;

	this->_brain = new Brain;
	*this->_brain = *other._brain;
}

// Copy assignment operator overload
Dog&	Dog::operator= (const Dog& other) {
	std::cout << "Dog calls copy assignment." << std::endl;

	if (this != &other) {
		*this->_brain = *other._brain;
	}

	return (*this);
}

// Destructor
Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog ran away~" << std::endl;
}

// Overridden function
void	Dog::makeSound(void) const {
	std::cout << "Dog says: Woof-Woof." << std::endl;
}

// Dog functions
Brain*	Dog::getBrain(void) const {
	return (this->_brain);
}
