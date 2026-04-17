/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 18:03:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void) {
	this->_name = "Unnamed";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap " << this->_name << " created." << std::endl;
}

// Constructor with parameters
ScavTrap::ScavTrap(const std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap " << this->_name << " created." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
ScavTrap&	ScavTrap::operator= (const ScavTrap& other) {
	std::cout << "ScavTrap copies " << other._name << std::endl;

	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}

	return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
}

// Overridden functions
void	ScavTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is dead!\n" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is out of energy!\n" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->_name
		<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
	std::cout << "attacks " << target << " for " << this->_attackDamage
		<< " damage points." << std::endl;

	this->_energyPoints--;
}

// ScavTrap unique function
void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name
		<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
	std::cout << "is now in Gate keeper mode\n" << std::endl;
}