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
Ice::Ice(void) {

	this->_type = "ice";
}

// Copy constructor
Ice::Ice(const Ice& other) {

	*this = other;
}

// Copy assignment operator overload
Ice&	Ice::operator= (const Ice& other) {

	return (*this);
}

// Ice function
AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
