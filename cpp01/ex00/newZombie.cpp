/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:06:29 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 18:14:17 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor with parameter
Zombie::Zombie( std::string name ) : name(name) {
	std::cout << "new zombie created" << std::endl;
}

Zombie*	Zombie::newZombie( std::string name ) {
	return (new Zombie(name));
}
