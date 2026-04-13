/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 19:13:07 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie		stackZombie;
	const int	N = 5;
	Zombie		*horde;

	horde = stackZombie.zombieHorde(N, "Horde zombie");
	std::cout << std::endl;
	for (int i = 0; i < N; i++) {
		horde->announce();
	}
	std::cout << std::endl;
	horde[1].announce();
	std::cout << std::endl;
	delete[] horde;
}
