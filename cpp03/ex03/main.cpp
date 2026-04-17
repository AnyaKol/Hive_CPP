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

#include "DiamondTrap.hpp"

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTORS TESTS ***" << std::endl;
	{
		DiamondTrap	a("٩꒰ʘʚʘ๑꒱۶");
		std::cout << std::endl;
		DiamondTrap	b(a);
		std::cout << std::endl;
		DiamondTrap	c("(๑´• .̫ •ू`๑)");
		std::cout << std::endl;
		ScavTrap	d = DiamondTrap("Shell(ᗒᗣᗕ)՞");
		std::cout << std::endl;
		FragTrap	e = DiamondTrap("🐺（ΦωΦ）");
		std::cout << std::endl;
		ClapTrap	f = DiamondTrap("⊙▂⊙Bot");
		std::cout << std::endl; 

		c = a;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\t*** BASIC FUNCTIONS TESTS ***" << std::endl;
	{
		ClapTrap	bot("Bot");
		std::cout << std::endl;
		ScavTrap	shell("Shell");
		std::cout << std::endl;
		FragTrap	smile("🤖");
		std::cout << std::endl;
		DiamondTrap	a("=＾● ⋏ ●＾=");
		std::cout << std::endl;
		ClapTrap	b = DiamondTrap("꜀( ˊ̠˂˃ˋ̠ )꜆Bot");

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
   		smile.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		smile.takeDamage(7);
		std::cout << "> repair" << std::endl;
		smile.beRepaired(5);
		std::cout << "> special" << std::endl;
		smile.highFivesGuys();

		std::cout << std::endl;
		std::cout << "> attack" << std::endl;
   		a.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		a.takeDamage(7);
		std::cout << "> repair" << std::endl;
		a.beRepaired(5);
		std::cout << "> special 1" << std::endl;
		a.guardGate();
		std::cout << "> special 2" << std::endl;
		a.highFivesGuys();
		std::cout << "> special 3" << std::endl;
		a.whoAmI();

		std::cout << std::endl;

		std::cout << "> attack" << std::endl;
   		b.attack("PracticeTarget");
		std::cout << "> take damage" << std::endl;
		b.takeDamage(7);
		std::cout << "> repair" << std::endl;
		b.beRepaired(5);
		//b.guardGate();
		//b.highFivesGuys();
		//b.whoAmI();

		std::cout << "\n\t*** ADDITIONAL TESTS ***" << std::endl;

		std::cout << "> special" << std::endl;
		a.highFivesGuys();
		std::cout << "> attack" << std::endl;
		a.attack("ಠ_ರೃ");
		std::cout << "> take damage" << std::endl;
		a.takeDamage(2);
		std::cout << "> repair" << std::endl;
		a.beRepaired(0);
		std::cout << "> repair(x50)" << std::endl;
		for (int i = 0; i < 50; i++)
			a.beRepaired(1);
		std::cout << "> take damage" << std::endl;
		a.takeDamage(3);
		std::cout << "> attack" << std::endl;
		a.attack("（。ˇ ⊖ˇ）♡");
		std::cout << "> take damage" << std::endl;
		a.takeDamage(100);
		std::cout << "> special" << std::endl;
		a.highFivesGuys();
		
	}

	return 0;
}
