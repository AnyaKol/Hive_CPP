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

//template <typename T>
//constexpr void	printElement(T elem) {
//	std::cout << elem << " ";
//}

static void	printChar(char elem) {
	std::cout << elem << " ";
}

static void	printInt(int elem) {
	std::cout << elem << " ";
}

static void	printStr(std::string elem) {
	std::cout << elem << " ";
}

int main( void ) {

	//auto printElement = [](auto elem) {
	//	std::cout << elem << " ";
	//};

	std::cout << "\n\t*** TESTS ***\n" << std::endl;

	std::array a {'a', 'b', 'c', 'd', 'e'};
	std::vector<int> b = {1, 2, 3, 4, 5};
	std::string c[] = {"s1", "s2", "s3", "s4", "s5"};

	std::cout << "char array: ";
	::iter(a, a.size(), printChar);
	std::cout << "\nint vector: ";
	::iter(b, b.size(), printInt);
	std::cout << "\nstring[]: ";
	::iter(c, 5, printStr);
	std::cout << std::endl;

	return (0); 
}
