/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:49:41 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 19:11:37 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int N, std::string name ) {
	Zombie*	horde = new Zombie[N];

	if (N <= 0) {
		delete[] horde;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		horde[i].name = name;
	return (&horde[0]);
}
