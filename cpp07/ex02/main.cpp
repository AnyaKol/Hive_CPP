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

#include "Array.hpp"

#include <iostream>
#include <array>

int main( void ) {

	std::cout << "\n\t*** TESTS ***\n" << std::endl;

	//Array a(5);
	//std::array b {'a', 'b', 'c', 'd', 'e'};


	//std::cout << "char array: ";

	int * a = new int();
	std::cout << "a: " << a << std::endl;
	std::cout << "*a: " << *a << std::endl;
	*a = 5;
	std::cout << "a: " << a << std::endl;
	std::cout << "*a: " << *a << std::endl;
	delete a;

	return (0); 
}
