/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:46:33 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 16:46:34 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void) : AMateria("DefaultType") {}

// Constructor with parameter
AMateria::AMateria(std::string const& type) {
	this->_type = type;
}

// Copy constructor
AMateria::AMateria(const AMateria&) {}

// Copy assignment operator overload
AMateria&	AMateria::operator= (const AMateria&) {

	return (*this);
}

// Inserion operator overload
std::ostream&	operator<< (std::ostream& output, const AMateria& other) {
	output << other.getType();

	return (output);
}

// AMateria function
std::string const&	AMateria::getType() const {
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Using " << *this << " on " << target.getName() << std::endl;
}
