/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:20:16 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 17:20:17 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default constructor
Ice::Ice(void) : AMateria() {
	this->_type = "ice";

	std::cout << "Ice " << *this << " created." << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria() {

	this->_type = other._type;
	std::cout << "Ice " << *this << " created from " << other << "."
		<< std::endl;
}

// Copy assignment operator overload
Ice&	Ice::operator= (const Ice& other) {

	//(void) other;
	std::cout << "Ice " << *this << " copies " << other << "." << std::endl;
	return (*this);
}

// Destructor
Ice::~Ice(void) {
	std::cout << "Ice " << *this << " destroyed." << std::endl;
}

// Ice function
AMateria*	Ice::clone() const {
	std::cout << "Ice " << *this << " is cloned." << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
