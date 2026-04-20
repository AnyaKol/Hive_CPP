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
Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal calls default constructor." << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : _type("Animal") {
	std::cout << "Animal calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
Animal&	Animal::operator= (const Animal& other) {
	std::cout << "Animal calls copy assignment." << std::endl;

	(void) other;
	return (*this);
}

// Destructor
Animal::~Animal(void) {
	std::cout << "Animal ran away~" << std::endl;
}

// Animal function
const std::string&	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::makeSound(void) const {
	std::cout << "Animal makes some animal sounds." << std::endl;
}
