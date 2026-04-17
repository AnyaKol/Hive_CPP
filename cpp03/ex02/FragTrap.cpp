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

// FragTrap unique function
void	FragTrap::highFivesGuys(void) {

	std::cout << "FragTrap " << this->_name
		<< " (" << this->_hitPoints << "|" << this->_energyPoints << "): ";
	std::cout << "wants to give you a high-five 🫣\n" << std::endl;
}
