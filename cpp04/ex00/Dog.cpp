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
Dog::Dog(void) : Animal() {
	this->_type = "Dog";
	std::cout << "Dog calls default constructor." << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal() {
	std::cout << "Dog calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
Dog&	Dog::operator= (const Dog& other) {
	std::cout << "Dog calls copy assignment." << std::endl;

	(void) other;
	return (*this);
}

// Destructor
Dog::~Dog(void) {
	std::cout << "Dog ran away~" << std::endl;
}

// Overridden function
void	Dog::makeSound(void) const {
	std::cout << "Dog says: Woof-Woof." << std::endl;
}
