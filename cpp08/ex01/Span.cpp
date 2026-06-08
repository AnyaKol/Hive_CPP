/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:24:48 by akolupae          #+#    #+#             */
/*   Updated: 2026/06/05 19:25:26 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <cassert>

Span::Span(void) : Span(0) {}

Span::Span(unsigned int N) : _max_size(N), _size(0), _ptr(nullptr) {

	if (this->_max_size > 0)
		this->_ptr = new int[N];
}

Span::Span(const Span& other) : Span(other._max_size) {

	*this = other;
}

const Span&	Span::operator=(const Span& other) {

	if (this->_max_size != other._max_size) {
		delete[] this->_ptr;
		this->_max_size = other._max_size;
		this->_ptr = new int[this->_max_size];
	}

	for (unsigned int i = 0; i < this->_max_size; i++)
		this->_ptr[i] = other._ptr[i];
	this->_size = other._size;

	return (*this);
}

Span::~Span() {
	delete[] this->_ptr;
}

// Getters
const unsigned int&	Span::getMaxSize(void) const {
	return (this->_max_size);
}

const unsigned int&	Span::getSize(void) const {
	return (this->_size);
}

const int*	Span::getPtr(void) const {
	return (this->_ptr);
}

int&	Span::operator[](unsigned int pos) {

	assert (pos < this->_max_size);
	return (this->_ptr[pos]);
}

const int&	Span::operator[](unsigned int pos) const {

	assert (pos < this->_max_size);
	return ( const_cast<const int&>(this->_ptr[pos]) );
}

// Span functions
void	Span::addNumber(int num) {

	if (this->_size == this->_max_size)
		throw ( Span::MaxSizeReached() );
	
	this->_ptr[this->_size] = num;
	this->_size++;
}

unsigned int	Span::shortestSpan(void) const {

	if (this->_size < 2)
		throw (Span::SpanTooShort());

	unsigned int	min = _span(this->_ptr[0], this->_ptr[1]);
	for (unsigned int i = 0; i < this->_size - 1; i++) {
		unsigned int	temp;
		for (unsigned int j = i + 1; j < this->_size; j++) {
			temp = _span(this->_ptr[i], this->_ptr[j]);
			if (temp < min)
				min = temp;
		}
	}
	return (min);
}

unsigned int	Span::longestSpan(void) const {

	if (this->_size < 2)
		throw (Span::SpanTooShort());

	unsigned int	max = _span(this->_ptr[0], this->_ptr[1]);
	for (unsigned int i = 0; i < this->_size - 1; i++) {
		unsigned int	temp;
		for (unsigned int j = i + 1; j < this->_size; j++) {
			temp = _span(this->_ptr[i], this->_ptr[j]);
			if (temp > max)
				max = temp;
		}
	}
	return (max);
}

// Helper
unsigned int	Span::_span(int a, int b) const {

	if (a > b)
		return (static_cast<unsigned int>(a) - static_cast<unsigned int>(b));
	return (static_cast<unsigned int>(b) - static_cast<unsigned int>(a));
}

// Exception
const std::string	Span::MaxSizeReached::_msg
	= "Maximum size reached.";

const char*	Span::MaxSizeReached::what(void) const noexcept {
	return ( this->_msg.c_str() );
}

const std::string	Span::SpanTooShort::_msg
	= "Span is too short.";

const char*	Span::SpanTooShort::what(void) const noexcept {
	return ( this->_msg.c_str() );
}