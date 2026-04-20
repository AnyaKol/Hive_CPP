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
AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << "AAnimal calls default constructor." << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) : _type("AAnimal") {
	std::cout << "AAnimal calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
AAnimal&	AAnimal::operator= (const AAnimal& other) {
	std::cout << "AAnimal calls copy assignment." << std::endl;

	(void) other;
	return (*this);
}

// Destructor
AAnimal::~AAnimal(void) {
	std::cout << "AAnimal ran away~" << std::endl;
}

// AAnimal function
const std::string&	AAnimal::getType(void) const {
	return (this->_type);
}

void	AAnimal::makeSound(void) const {
	std::cout << "AAnimal makes some animal sounds." << std::endl;
}
