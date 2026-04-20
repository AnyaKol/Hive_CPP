/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:28:20 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 14:28:25 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat calls default constructor." << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	std::cout << "WrongCat calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
WrongCat&	WrongCat::operator= (const WrongCat& other) {
	std::cout << "WrongCat calls copy assignment." << std::endl;

	(void) other;
	return (*this);
}

// Destructor
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat ran away~" << std::endl;
}

// Overridden function
void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat says: WrongMeow-Meow, Mrrr." << std::endl;
}
