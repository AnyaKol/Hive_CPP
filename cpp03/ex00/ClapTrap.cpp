/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:17:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
: _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}

// Constructor with parameters
ClapTrap::ClapTrap(const std::string name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _attackDamage(0) {
	std::cout << "ClapTrap calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
ClapTrap&	ClapTrap::operator= (const ClapTrap& other) {
	std::cout << "ClapTrap copies " << other._name << std::endl;

	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
	}

	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

// ClapTrap actions
void	ClapTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is dead!\n" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is out of energy!\n" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name
		<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
	std::cout << "attacks " << target << " for " << this->_attackDamage
		<< " damage points." << std::endl;

	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is dead!\n" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name
		<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
	std::cout << "takes " << amount << " points of damage." << std::endl;

	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is dead!\n" << std::endl;
	} else {
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is still standing.\n" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is dead!\n" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is out of energy!\n" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name
		<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
	std::cout << "repaires " << amount << " hit points." << std::endl;

	this->_energyPoints--;

	if (amount > 0) {
		this->_hitPoints += amount;

		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "is feeling better.\n" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name
			<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
		std::cout << "doesn't feel anything.\n" << std::endl;
	}
}
