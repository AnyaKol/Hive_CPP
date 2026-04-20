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
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal calls default constructor." << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : WrongAnimal() {
	std::cout << "WrongAnimal calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
WrongAnimal&	WrongAnimal::operator= (const WrongAnimal& other) {
	std::cout << "WrongAnimal calls copy assignment." << std::endl;

	(void) other;
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal ran away~" << std::endl;
}

// WrongAnimal function
const std::string&	WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal makes some Wrong sounds." << std::endl;
}