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
Dog::Dog(std::string name) : Animal(name, "Dog") {}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {}

// Copy assignment operator overload
Dog&	Dog::operator= (const Dog& other){

	this->Animal::operator=(other);

	return (*this);
}

// Destructor
Dog::~Dog(void) {}

// Overridden function
void	Dog::makeSound(void) const {
	this->_announce();
	std::cout << " says: Woof-Woof." << std::endl;
}
