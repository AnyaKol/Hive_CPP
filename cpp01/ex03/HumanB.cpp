/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:04:33 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 20:57:53 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL) {
	std::cout << "HumanB " << this->_name << " created." << std::endl;
}

// Destructor
HumanB::~HumanB(void) {
	std::cout << "HumanB " << this->_name << " destroyed." << std::endl;
}

void	HumanB::attack(void) {
	if (this->_weapon == NULL) {
		std::cout << this->_name << " doesn't have a weapon." << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType()
	<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
