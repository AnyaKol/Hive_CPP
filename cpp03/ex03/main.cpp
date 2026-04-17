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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTORS TESTS ***" << std::endl;
	{
		FragTrap	a("🦊");
		std::cout << std::endl;
		FragTrap	b(a);
		std::cout << std::endl;
		FragTrap	c("🐻");
		std::cout << std::endl;
		ClapTrap	d = ScavTrap("ShellBot");
		std::cout << std::endl;
		ClapTrap	e = ScavTrap("🐺Bot");
		std::cout << std::endl; 

		c = a;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\t*** BASIC FUNCTIONS TESTS ***" << std::endl;
	{
		ClapTrap	bot("Bot");
		ScavTrap	shell("Shell");
		FragTrap	a("🤖");
		FragTrap	b("👽");
		FragTrap	c("🎃");
		ClapTrap	d = FragTrap("🐺Bot");

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		bot.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		bot.takeDamage(7);
		std::cout << "> repair" << std::endl;
		bot.beRepaired(5);

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		shell.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		shell.takeDamage(7);
		std::cout << "> repair" << std::endl;
		shell.beRepaired(5);
		std::cout << "> special" << std::endl;
		shell.guardGate();

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		a.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		a.takeDamage(7);
		std::cout << "> repair" << std::endl;
		a.beRepaired(5);
		std::cout << "> special" << std::endl;
		a.highFivesGuys();

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		d.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		d.takeDamage(7);
		std::cout << "> repair" << std::endl;
		d.beRepaired(5);
		std::cout << "> special" << std::endl;
		//d.highFivesGuys();

		std::cout << "\n\t*** ADDITIONAL TESTS ***" << std::endl;

		std::cout << "> special" << std::endl;
		b.highFivesGuys();
		std::cout << "> special" << std::endl;
		b.highFivesGuys();
		std::cout << "> attack" << std::endl;
		b.attack("🦀");
		std::cout << "> take damage" << std::endl;
		b.takeDamage(2);
		std::cout << "> repair" << std::endl;
		b.beRepaired(0);
		std::cout << "> repair(x100)" << std::endl;
		for (int i = 0; i < 100; i++)
			b.beRepaired(1);
		std::cout << "> take damage" << std::endl;
		b.takeDamage(3);
		std::cout << "> attack" << std::endl;
		b.attack("🦖");
		std::cout << "> take damage" << std::endl;
		b.takeDamage(100);
		std::cout << "> special" << std::endl;
		b.highFivesGuys();

		std::cout << std::endl;

		std::cout << "> special" << std::endl;
		c.highFivesGuys();
		std::cout << "> take damage" << std::endl;
		c.takeDamage(150);
		std::cout << "> attack" << std::endl;
		c.attack("🦨");
		std::cout << "> repair" << std::endl;
		c.beRepaired(15);
	}

	return 0;
}
