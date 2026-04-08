/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:44:42 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/08 17:44:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static void	Megaphone(std::string str);

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++)
			Megaphone(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}

/* Using C++11 for range-based for-loop */
static void	Megaphone(std::string str) {
	for (char &c : str)
		c = std::toupper(c);
	std::cout << str;
}
