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

// begin()	points to the first element of array;
// end()	points to position after last element.
// std::next(iter, n) returns a copy of iter incremented by n.
// In 'for' loop ++i and i++ produce the same result.
template <typename T, typename U = typename T::iterator>
constexpr static void	printArray(T& arr) {

	U	first = arr.begin();
	U	last = arr.end();

	for (; first != last; first++) {
		std::cout << *first;
		if (std::next(first, 1) != last)
			std::cout << ", ";
	}
}

template <typename T, typename U = typename T::iterator>
constexpr static void	findInArray(T& arr, int n) {

	U it = easyfind(arr, n);

	printArray(arr);
	std::cout << std::endl;
	if (it == arr.end())
		std::cout << "Not found: " << n << std::endl;
	else
		std::cout << "Found: " << *it << std::endl;
}


int main( void ) {

	std::cout << "\n\t*** TESTS ***\n" << std::endl;
	{
		std::array<int, 5> a = {1, 2, 3, 4, 5};
		std::vector<int> b = {1, 2, 3, 4, 5};
		std::deque<int> c = {1, 2, 3, 4, 5};
		std::list<int> d = {1, 2, 3, 4, 5};
		int	n = 1;


		std::cout << "std::array a: ";
		findInArray(a, n);
		std::cout << std::endl;

		std::cout << "std::vector b: ";
		findInArray(b, n);
		std::cout << std::endl;

		std::cout << "std::deque c: ";
		findInArray(c, n);
		std::cout << std::endl;

		std::cout << "std::list d: ";
		findInArray(d, n);
		std::cout << std::endl;
	}

	return (0); 
}

