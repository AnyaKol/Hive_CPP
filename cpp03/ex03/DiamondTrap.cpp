/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:34:53 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 21:34:55 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void) : _name("Unnamed") {
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;

	std::cout << "DiamondTrap " << this->_name << " created." << std::endl;
}

// Constructor with parameters
DiamondTrap::DiamondTrap(const std::string name) : _name(name) {
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;

	std::cout << "DiamondTrap " << this->_name << " created." << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	std::cout << "DiamondTrap calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
DiamondTrap&	DiamondTrap::operator= (const DiamondTrap& other) {
	std::cout << "DiamondTrap copies " << other._name << std::endl;

	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}

	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name << " destroyed." << std::endl;
}
