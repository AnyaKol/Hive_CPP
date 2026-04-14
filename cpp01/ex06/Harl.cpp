/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:24:40 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 19:40:38 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl (void) {
	std::cout << "Harl created." << std::endl;
}

Harl::~Harl (void) {
	std::cout << "Harl destroyed." << std::endl;
}

void	Harl::debug(void) {
	std::cout << " * DEBUG message * " << std::endl;
}

void	Harl::info(void) {
	std::cout << " * INFO message * " << std::endl;
}

void	Harl::warning(void) {
	std::cout << " * WARNING message * " << std::endl;
}

void	Harl::error(void) {
	std::cout << " * ERROR message * " << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	arr[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int			i;

	for (i = 0; i < 4; i++) {
		if (level == arr[i])
			break ;
	}
	switch (i) {
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break ;
	default:
		std::cout << " [No message] " << std::endl;
	}
}
