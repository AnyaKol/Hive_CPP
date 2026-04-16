/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:04:33 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 20:42:22 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon& weapon)
: _name(name), _weapon(weapon) {
	std::cout << "HumanA " << this->_name << " created." << std::endl;
}

// Destructor
HumanA::~HumanA(void) {
	std::cout << "HumanA " << this->_name << " destroyed." << std::endl;
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType()
	<< std::endl;
}
