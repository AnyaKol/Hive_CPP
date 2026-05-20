/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:54:51 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/20 19:28:07 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Copy constructor
Data::Data(const Data& other) {
	*this = other;
}

// Copy assignment operator overload
Data&	Data::operator= (const Data& other) {

	if (this != &other) {
		this->_value = other._value;
	}

	return (*this);
}

const int&	Data::getValue() const {
	return (this->_value);
}

void	Data::setValue(int val) {

	this->_value = val;
}
