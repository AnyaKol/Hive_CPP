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
ScavTrap::ScavTrap(const ScavTrap& other) {
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

	if (!this->_checkDeath())
		return ;
	if (!this->_checkEnergy())
		return ;

	this->_announce();
	std::cout << "attacks " << target << " for " << this->_attackDamage
		<< " damage points >:)\n" << std::endl;

	this->_energyPoints--;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	
	if (!this->_checkDeath())
		return ;

	this->_announce();
	std::cout << "takes " << amount << " points of damage >:(" << std::endl;

	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		this->_checkDeath();
	} else {
		this->_hitPoints -= amount;
		this->_announce();
		std::cout << "is still standing >:/\n" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount) {

	if (!this->_checkDeath())
		return ;
	if (!this->_checkEnergy())
		return ;

	this->_announce();
	std::cout << "repaires " << amount << " hit points +_+" << std::endl;

	this->_energyPoints--;

	if (amount > 0) {
		this->_hitPoints += amount;

		if (this->_hitPoints > 100)
			this->_hitPoints = 100;
		this->_announce();
		std::cout << "is feeling better ^_^\n" << std::endl;
	} else {
		this->_announce();
		std::cout << "doesn't feel anything ._.\n" << std::endl;
	}
}

// ScavTrap unique function
void	ScavTrap::guardGate(void) {

	if (!this->_checkDeath())
		return ;

	this->_announce();
	std::cout << "is now in Gate keeper mode >:|\n" << std::endl;
}

// Helper functions
void	ScavTrap::_announce(void) const {
	std::cout << "ScavTrap " << this->_name
		<< " (" << this->_hitPoints << "/100 | "
		<< this->_energyPoints << "/50): ";
}

bool	ScavTrap::_checkDeath(void) const {
	if (this->_hitPoints == 0) {
		this->_announce();
		std::cout << "is dead X|\n" << std::endl;
		return (false);
	}
	return (true);
}

bool	ScavTrap::_checkEnergy(void) const {
	if (this->_energyPoints == 0) {
		this->_announce();
		std::cout << "is out of energy :(\n" << std::endl;
		return (false);
	}
	return (true);
}
