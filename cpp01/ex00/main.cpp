/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 18:34:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie *new_zombie;
	Zombie *another_zombie;

	new_zombie = newZombie("NewZombie");
	another_zombie = newZombie("AnotherZombie");
	std::cout << std::endl;
	new_zombie->announce();
	another_zombie->announce();
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		randomChump("Chump");
	}
	std::cout << std::endl;
	delete new_zombie;
	delete another_zombie;
	return (0);
}
