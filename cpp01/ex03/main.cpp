/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:12:12 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 21:03:24 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << std::endl << "*** Additional tests ***" << std::endl << std::endl;
		Weapon	stick = Weapon("stick");
		HumanA	A("HumanA", stick);
		HumanB	B("HumanB");

		std::cout << std::endl;
		A.attack();
		B.attack();
		B.setWeapon(stick);
		B.attack();
		stick.setType("broken stick");
		A.attack();
		B.attack();
	}
	return 0;
}
