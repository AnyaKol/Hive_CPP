/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/12 10:00:52 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

int	main(int argc, char **argv) {

	for (int i = 1; i < argc; i++) {
		ScalarConverter::convert(argv[i]);
		std::cout << std::endl;
	}

	//ScalarConverter a;
	//ScalarConverter b(a);
	//b = a;
	//ScalarConverter *c = new ScalarConverter();
	//delete c;

	return 0;
}
