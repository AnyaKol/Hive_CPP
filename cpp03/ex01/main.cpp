/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 18:59:35 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTORS TESTS ***" << std::endl;
	{
		ScavTrap	a("A-shell");
		std::cout << std::endl;
		ScavTrap	b(a);
		std::cout << std::endl;
		ScavTrap	c("C-shell");
		std::cout << std::endl;
		ClapTrap	d = ScavTrap("ShellBot");
		std::cout << std::endl;

		c = a;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\t*** BASIC FUNCTIONS TESTS ***" << std::endl;
	{
		ClapTrap	bot("Bot");
		ScavTrap	a("A-shell");
		ScavTrap	b("B-shell");
		ScavTrap	c("C-shell");
		ClapTrap	d = ScavTrap("ShellBot");

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		bot.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		bot.takeDamage(7);
		std::cout << "> repair" << std::endl;
		bot.beRepaired(5);

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		a.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		a.takeDamage(7);
		std::cout << "> repair" << std::endl;
		a.beRepaired(5);
		std::cout << "> special" << std::endl;
		a.guardGate();

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		d.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		d.takeDamage(7);
		std::cout << "> repair" << std::endl;
		d.beRepaired(5);
		std::cout << "> special" << std::endl;
		//d.guardGate();

		std::cout << "\n\t*** ADDITIONAL TESTS ***" << std::endl;

		std::cout << "> special" << std::endl;
		b.guardGate();
		std::cout << "> special" << std::endl;
		b.guardGate();
		std::cout << "> attack" << std::endl;
		b.attack("B-Target");
		std::cout << "> take damage" << std::endl;
		b.takeDamage(2);
		std::cout << "> repair" << std::endl;
		b.beRepaired(0);
		std::cout << "> repair(x50)" << std::endl;
		for (int i = 0; i < 50; i++)
			b.beRepaired(1);
		std::cout << "> take damage" << std::endl;
		b.takeDamage(3);
		std::cout << "> attack" << std::endl;
		b.attack("EnemyBee");
		std::cout << "> take damage" << std::endl;
		b.takeDamage(100);
		std::cout << "> special" << std::endl;
		b.guardGate();

		std::cout << std::endl;

		std::cout << "> special" << std::endl;
		c.guardGate();
		std::cout << "> take damage" << std::endl;
		c.takeDamage(150);
		std::cout << "> attack" << std::endl;
		c.attack("C-Target");
		std::cout << "> repair" << std::endl;
		c.beRepaired(15);
	}

	return 0;
}
