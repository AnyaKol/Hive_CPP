/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:24:40 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 18:09:33 by akolupae         ###   ########.fr       */
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
	void	(Harl::* fun[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (level == arr[i])
			(this->*fun[i])();
	};
}
