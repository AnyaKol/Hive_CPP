/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:20:36 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 17:20:37 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default constructor
Cure::Cure(void) : AMateria() {
	this->_type = "cure";

	std::cout << "Cure " << *this << " created." << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& other) : AMateria() {

	this->_type = other._type;
	std::cout << "Cure " << *this << " created from " << other << "."
		<< std::endl;
}

// Copy assignment operator overload
Cure&	Cure::operator= (const Cure& other) {

	//(void) other;
	std::cout << "Cure " << *this << " copies " << other << "." << std::endl;
	return (*this);
}

// Destructor
Cure::~Cure(void) {
	std::cout << "Cure " << *this << " destroyed." << std::endl;
}

// Cure function
AMateria*	Cure::clone() const {
	std::cout << "Cure " << *this << " is cloned." << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
