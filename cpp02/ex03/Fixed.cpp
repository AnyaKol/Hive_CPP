/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 21:20:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 22:23:21 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _rawBits(val << this->_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : _rawBits(round(val * (float)pow(2, this->_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator overload
Fixed&	Fixed::operator= (const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_rawBits = other.getRawBits();

	return (*this);	
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ( (float)(this->_rawBits / pow(2, this->_bits)) );
}

int		Fixed::toInt(void) const {
	return ( round(this->toFloat()) );
}

// Insertion operator overload
// omitting keyword 'friend': can't use outside of class
std::ostream&	operator<< (std::ostream& output, const Fixed& other) {
	output << other.toFloat();
	return (output);
}

// Overloading more operators
bool	Fixed::operator> (const Fixed& other) const {
	return ( this->toFloat() > other.toFloat() );
}

bool	Fixed::operator< (const Fixed& other) const {
	return ( this->toFloat() < other.toFloat() );
}

bool	Fixed::operator>= (const Fixed& other) const {
	return ( this->toFloat() >= other.toFloat() );
}

bool	Fixed::operator<= (const Fixed& other) const {
	return ( this->toFloat() <= other.toFloat() );
}

bool	Fixed::operator== (const Fixed& other) const {
	return ( this->toFloat() == other.toFloat() );
}

bool	Fixed::operator!= (const Fixed& other) const {
	return ( this->toFloat() != other.toFloat() );
}

// Overloading arithmetic operators
float	Fixed::operator+ (const Fixed& other) const {
	return ( this->toFloat() + other.toFloat() );
}

float	Fixed::operator- (const Fixed& other) const {
	return ( this->toFloat() - other.toFloat() );
}

float	Fixed::operator* (const Fixed& other) const {
	return ( this->toFloat() * other.toFloat() );
}

float	Fixed::operator/ (const Fixed& other) const {
	if (other.toFloat() == 0)
		return (0);
	return ( this->toFloat() / other.toFloat() );
}

// Overloading increment/decrement
// postfix ++/-- must have 'int' as it's argument
Fixed	Fixed::operator++ (int) {
	Fixed	temp(*this);

	this->setRawBits(this->_rawBits + 1);
	return ( temp );
}

Fixed&	operator++ (Fixed& other) {
	other.setRawBits(other._rawBits + 1);
	return ( other );
}

Fixed	Fixed::operator-- (int) {
	Fixed	temp(*this);

	this->setRawBits(this->_rawBits - 1);
	return ( temp );
}

Fixed&	operator-- (Fixed& other) {
	other.setRawBits(other._rawBits - 1);
	return ( other );
}

// Overloading existing functions
// static function can be called without creating an object
// omitting keyword 'static': can't create static function with static linkage
// (static - only for this file); compiler remembers it's static
Fixed&	Fixed::max (const Fixed& a, const Fixed& b) {
	if (a >= b)
		return ( (Fixed&) a );
	return ( (Fixed&) b );
}

Fixed&	Fixed::max (Fixed& a, Fixed& b) {
	if (a >= b)
		return (a);
	return (b);
}

Fixed&	Fixed::min (const Fixed& a, const Fixed& b) {
	if (a <= b)
		return ( (Fixed&) a );
	return ( (Fixed&) b );
}

Fixed&	Fixed::min (Fixed& a, Fixed& b) {
	if (a <= b)
		return (a);
	return (b);
}
