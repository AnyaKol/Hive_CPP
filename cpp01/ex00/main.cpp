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
	Zombie	stackZombie;
	Zombie *newZombie = stackZombie.newZombie("NewZombie");
	Zombie *anotherZombie = stackZombie.newZombie("AnotherZombie");
	std::cout << std::endl;
	newZombie->announce();
	anotherZombie->announce();
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		stackZombie.randomChump("Chump");
	}
	std::cout << std::endl;
	delete newZombie;
	delete anotherZombie;
}
