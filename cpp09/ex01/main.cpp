/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:53:51 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/26 17:08:53 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

int main( int argc, char** argv ) {

	RPN	base;

	for (int i = 1; i < argc; i++) {
		try {
			base.add(std::string_view{argv[i]});
		} catch (std::exception &e) {
			RPN::printError(std::string_view{e.what()});
			return (1);
		}
	}
	try {
		std::cout << base.getResult() << std::endl;
	} catch (std::exception &e) {
		RPN::printError(std::string_view{e.what()});
		return (1);
	}

	return (0); 
}


