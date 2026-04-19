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
Cure::Cure(void) {

	this->_type = "cure";
}

// Copy constructor
Cure::Cure(const Cure& other) {

	*this = other;
}

// Copy assignment operator overload
Cure&	Cure::operator= (const Cure& other) {

	return (*this);
}

// Cure function
AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
