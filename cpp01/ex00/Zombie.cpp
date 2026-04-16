/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:02:31 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 18:32:56 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie( void ) : _name("unnamed") {
	std::cout << "zombie created" << std::endl;
}

// Constructor with parameter
Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << name << " zombie created" << std::endl;
}

// Destructor
Zombie::~Zombie( void ) {
	std::cout << this->_name << " destroyed" << std::endl;
}

void	Zombie::setName( const std::string& name ) {
	this->_name = name;
}

void	Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
