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
Cat::Cat(std::string name) : Animal(name, "Cat") {}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {}

// Copy assignment operator overload
Cat&	Cat::operator= (const Cat& other){

	this->Animal::operator=(other);

	return (*this);
}

// Destructor
Cat::~Cat(void) {}

// Overridden function
void	Cat::makeSound(void) const {
	this->_announce();
	std::cout << " says: Meow-Meow, Mrrr." << std::endl;
}
