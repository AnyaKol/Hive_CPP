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
Cat::Cat(void) : Animal() {
	this->_type = "Cat";
	std::cout << "Cat calls default constructor." << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal() {
	std::cout << "Cat calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
Cat&	Cat::operator= (const Cat& other) {
	std::cout << "Cat calls copy assignment." << std::endl;

	(void) other;
	return (*this);
}

// Destructor
Cat::~Cat(void) {
	std::cout << "Cat ran away~" << std::endl;
}

// Overridden function
void	Cat::makeSound(void) const {
	std::cout << "Cat says: Meow-Meow, Mrrr." << std::endl;
}
