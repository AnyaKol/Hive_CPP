/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:21:16 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 18:18:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	test_harl(Harl& harl, std::string level);	

int	main(void) {
	Harl		harl;

	test_harl(harl, "INFO");
	test_harl(harl, "WARNING");
	test_harl(harl, "DEBUG");
	test_harl(harl, "ERROR_");
	test_harl(harl, "ERROR");
	return (0);
}

static void	test_harl(Harl& harl, std::string level) {	
	std::cout << "Level: " << level << std::endl;
	harl.complain(level);
	std::cout << std::endl;
}
