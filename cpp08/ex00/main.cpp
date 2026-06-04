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

#include "easyfind.hpp"
#include "easyfind.tpp"

#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>

template <typename T, typename U = typename T::iterator>
constexpr static void	printArray(T& arr) {

	U	first = arr.begin();
	U	last = arr.end();

	for (; first != last; first++) {
		std::cout << *first;
		std::cout << ", ";
	}
}

int main( void ) {

	std::cout << "\n\t*** TESTS ***\n" << std::endl;
	{
		std::array<int, 5> a = {1, 2, 3, 4, 5};
		std::vector<int> b = {6, 7, 8, 9, 10};
		std::deque<int> c = {11, 12, 13, 14, 15};
		std::list<int> d = {16, 17, 18, 19, 20};
		int	found;


		std::cout << "std::array a: ";
		printArray(a);
		std::cout << std::endl;
		try {
			std::cout << "Found: " << *easyfind(a, 5) << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Not found: " << e.what() << "\n" << std::endl;
		}

		std::cout << "std::vector b: ";
		printArray(b);
		std::cout << std::endl;
		try {
			std::cout << "Found: " << *easyfind(b, 12) << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Not found: " << e.what() << "\n" << std::endl;
		}

		std::cout << "std::deque c: ";
		printArray(c);
		std::cout << std::endl;
		try {
			std::cout << "Found: " << *easyfind(c, 12) << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Not found: " << e.what() << "\n" << std::endl;
		}

		std::cout << "std::list d: ";
		printArray(d);
		std::cout << std::endl;
		try {
			std::cout << "Found: " << *easyfind(d, 12) << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Not found: " << e.what() << "\n" << std::endl;
		}
	}

	return (0); 
}

