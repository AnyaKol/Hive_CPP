/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:53:51 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/21 14:42:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>
#include <array>
#include <vector>

// printElement is lambda.
// auto keyword guesses varible type.
int main( void ) {

	auto printElement{ [](auto elem) {
		std::cout << elem;
	} };

	std::cout << "\n\t*** TESTS ***\n" << std::endl;
	
	std::array a {'a', 'b', 'c', 'd', 'e'};
	std::vector<int> b = {1, 2, 3, 4, 5};
	std::string c[] = {"s1", "s2", "s3", "s4", "s5"};

	std::cout << "char array: ";
	::iter(a, a.size(), printElement);
	std::cout << "\nint vector: ";
	::iter(b, b.size(), printElement);
	std::cout << "\nstring[]: ";
	::iter(c, 5, printElement);
	std::cout << std::endl;

	return (0); 
}
