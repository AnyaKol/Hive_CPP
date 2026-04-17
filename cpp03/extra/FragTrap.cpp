/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 18:03:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void) {
	this->_name = "Unnamed";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap " << this->_name << " created." << std::endl;
}

// Constructor with parameters
FragTrap::FragTrap(const std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap " << this->_name << " created." << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) {
	std::cout << "FragTrap calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
FragTrap&	FragTrap::operator= (const FragTrap& other) {
	std::cout << "FragTrap copies " << other._name << std::endl;

	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}

	return (*this);
}

// Destructor
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
}

// Overridden functions
void	FragTrap::attack(const std::string& target) {

	if (!this->_checkDeath())
		return ;
	if (!this->_checkEnergy())
		return ;

	this->_announce();
	std::cout << "attacks " << target << " for " << this->_attackDamage
		<< " damage points 😈\n" << std::endl;

	this->_energyPoints--;
}

void	FragTrap::takeDamage(unsigned int amount) {
	
	if (!this->_checkDeath())
		return ;

	this->_announce();
	std::cout << "takes " << amount << " points of damage 🥺" << std::endl;

	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		this->_checkDeath();
	} else {
		this->_hitPoints -= amount;
		this->_announce();
		std::cout << "is still standing 😤\n" << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount) {

	if (!this->_checkDeath())
		return ;
	if (!this->_checkEnergy())
		return ;

	this->_announce();
	std::cout << "repaires " << amount << " hit points 😃" << std::endl;

	this->_energyPoints--;

	if (amount > 0) {
		this->_hitPoints += amount;

		if (this->_hitPoints > 100)
			this->_hitPoints = 100;
		this->_announce();
		std::cout << "is feeling better 😚\n" << std::endl;
	} else {
		this->_announce();
		std::cout << "doesn't feel anything 😐\n" << std::endl;
	}
}

// FragTrap unique function
void	FragTrap::highFivesGuys(void) {

	if (!this->_checkDeath())
		return ;

	this->_announce();
	std::cout << "wants to give you a high-five 🫣\n" << std::endl;
}

// Helper functions
void	FragTrap::_announce(void) const {
	std::cout << "FragTrap " << this->_name
		<< " (" << this->_hitPoints << "/100 | "
		<< this->_energyPoints << "/100): ";
}

bool	FragTrap::_checkDeath(void) const {
	if (this->_hitPoints == 0) {
		this->_announce();
		std::cout << "is dead 😵\n" << std::endl;
		return (false);
	}
	return (true);
}

bool	FragTrap::_checkEnergy(void) const {
	if (this->_energyPoints == 0) {
		this->_announce();
		std::cout << "is out of energy 😴\n" << std::endl;
		return (false);
	}
	return (true);
}
