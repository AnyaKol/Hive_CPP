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

#include "BitcoinExchange.hpp"

#include <iostream>

int main( int argc, char** argv ) {

	if (argc != 2) {
		BitcoinExchange::printError(BitcoinExchange::ERR_NOFILE);
		return (1);
	}
	try {
		BitcoinExchange base("data.csv");

		base.convert(argv[1]);
	}
	catch (std::exception &e) {
		BitcoinExchange::printError(std::string_view{e.what()});
		return (1);
	}

	return (0); 
}


