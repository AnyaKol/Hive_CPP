/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/20 20:39:43 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <random>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void) {

	std::cout << "\n\t*** TESTS ***\n" << std::endl;

	Base* arr[10];

	for (int i = 0; i < 10; i++)
		arr[i] = generate();
	std::cout << std::endl;

	for (Base* ptr : arr) {
		identify(ptr);
	}
	std::cout << std::endl;

	for (Base* ptr : arr) {
		identify(*ptr);
	}
	std::cout << std::endl;

	for (Base* ptr : arr) {
		delete(ptr);
	}

	return 0;
}

Base*	generate(void) {

	static std::random_device	rd;
	static std::mt19937			range(rd());
	static std::uniform_int_distribution<int> dist(0, 3);
	int	res;

	res = dist(range) % 3;
	if (res == 0) {
		std::cout << "A";
		return (new A);
	}
	else if (res == 1) {
		std::cout << "B";
		return (new B);
	}
	else {
		std::cout << "C";
		return (new C);
	}
}

void	identify(Base* p) {

	if ( dynamic_cast<A*>(p) != nullptr )
		std::cout << "A";
	else if ( dynamic_cast<B*>(p) != nullptr )
		std::cout << "B";
	else if ( dynamic_cast<C*>(p) != nullptr )
		std::cout << "C";
}

void	identify(Base& p) {

	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A";
		return;
	}
	catch (std::exception& e) {}

	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B";
		return;
	}
	catch (std::exception& e) {}

	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "C";
		return;
	}
	catch (std::exception& e) {}
}
