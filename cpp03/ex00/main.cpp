/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:25:12 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTORS TESTS ***" << std::endl;
	{
		ClapTrap	a("Bot");
		ClapTrap	b(a);
		ClapTrap	c("Astrobot");

		c = b;
	}
	std::cout << std::endl;
	std::cout << "\n\t*** BASIC FUNCTIONS TESTS ***" << std::endl;
	{
		ClapTrap	a("Astrobot");
		ClapTrap	b("Beebot");
		ClapTrap	c("Cubot");

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		a.attack("SpaceTarget");
		std::cout << "> take damage" << std::endl;
		a.takeDamage(7);
		std::cout << "> repair" << std::endl;
		a.beRepaired(5);

		std::cout << "\n\t*** ADDITIONAL TESTS ***" << std::endl;

		std::cout << "> attack" << std::endl;
		b.attack("EnemyBee");
		std::cout << "> take damage" << std::endl;
		b.takeDamage(2);
		std::cout << "> repair" << std::endl;
		b.beRepaired(0);
		std::cout << "> repair(x10)" << std::endl;
		for (int i = 0; i < 10; i++)
			b.beRepaired(1);
		std::cout << "> take damage" << std::endl;
		b.takeDamage(3);
		std::cout << "> attack" << std::endl;
		b.attack("EnemyBee");
		std::cout << "> take damage" << std::endl;
		b.takeDamage(100);

		std::cout << std::endl;

		std::cout << "> take damage" << std::endl;
		c.takeDamage(15);
		std::cout << "> attack" << std::endl;
		c.attack("PracticeTarget");
		std::cout << "> repair" << std::endl;
		c.beRepaired(15);
	}

	return 0;
}
