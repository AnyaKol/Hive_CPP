/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 21:20:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 19:20:08 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
// Use '&' to avoid infinite recursion
// Will accept const and non-const reference, but prevents from modifying
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator overload
// [ a = b ] --> [ a.operator=(b) ]
Fixed &Fixed::operator= (const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_rawBits = other._rawBits;

	return (*this);	
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// 'const' after brackets means this function will not change anything inside
// the class.
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}
