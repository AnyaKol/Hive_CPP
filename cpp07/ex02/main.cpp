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
#include "Array.tpp"

#include <iostream>
#include <array>

template <typename T>
constexpr static void	printArray(T& arr) {

	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
		if (i < arr.size() - 1)
			std::cout << ", ";
	}
}

int main( void ) {

	std::cout << "\n\t*** CONSTRUCTOR TESTS ***\n" << std::endl;
	{
		Array<int> a(1);
		Array<int> b(5);

		try {
			a[0] = 45;
		} catch (std::exception &e) {
			std::cout << e.what() << "\n" << std::endl;
		}
		std::cout << "a size: " << a.size() << "\n";
		std::cout << "a element 0: " << a[0] << "\n";
		std::cout << "b size: " << b.size() << "\n";
		std::cout << "b element 0: " << b[0] << "\n" << std::endl;

		try {
			b[0] = 9;
			a = b;
			b[1] = 1;
			a[2] = 2;
		} catch (std::exception &e) {
			std::cout << e.what() << "\n" << std::endl;
		}

		Array<int> c(b);

		std::cout << "a size: " << a.size() << "\n";
		std::cout << "b size: " << b.size() << "\n";
		std::cout << "c size: " << c.size() << "\n" << std::endl;

		try {
			c[3] = 3;
		} catch (std::exception &e) {
			std::cout << e.what() << "\n" << std::endl;
		}
		std::cout << "int array a: ";
		printArray(a);
		std::cout << std::endl;
		std::cout << "int array b: ";
		printArray(b);
		std::cout << std::endl;
		std::cout << "int array c: ";
		printArray(c);
		std::cout << std::endl;
	}

	std::cout << "\n\t*** ARRAY TESTS ***\n" << std::endl;
	{
		Array<char> a(5);

		try {
			a[0] = 'a';
			a[4] = 'e';
			a[5] = 'f';
			a[2] = 'c';
		} catch (std::exception &e) {
			std::cout << e.what() << "\n" << std::endl;
		}

		std::cout << "char array a: ";
		printArray(a);
		std::cout << std::endl;
	}

	return (0); 
}

