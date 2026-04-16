/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:54:22 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 21:02:20 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(std::string type) : _type(type) {
	std::cout <<  this->getType() << " created." <<std::endl;
}

// Destructor
Weapon::~Weapon(void) {
	std::cout <<  this->getType() << " destroyed." <<std::endl;
}

const std::string&	Weapon::getType(void) {
	return ((const std::string&) this->_type);
}

void	Weapon::setType(std::string type) {
	std::cout <<  this->getType() << " -> ";
	this->_type = type;
	std::cout <<  this->getType() << std::endl;
}
