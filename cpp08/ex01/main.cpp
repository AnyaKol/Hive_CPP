/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:24:37 by akolupae          #+#    #+#             */
/*   Updated: 2026/06/05 19:24:39 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <climits>

#include <array>
#include <vector>
#include <deque>
#include <list>

static void	printSpan(const Span& sp);

int	main(void) {

	std::cout << "\n\t*** SUBJECT TESTS ***\n" << std::endl;
	{
		Span sp = Span(5);

		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\t*** CONTAINERS TESTS ***\n" << std::endl;
	{
		Span sp = Span(100);
		std::array<int, 10>	a = {1, 2, 3, 4, 5};
		std::vector<int>	b = {-21, -22, -23, -24, -25, -26};
		std::deque<int>		c = {301, 302, 303, 304, 305};
		std::list<int>		d = {4001, 4002, 4003, 4004, 4005};

		try {
			sp.addNumber(a, 5);
			sp.addNumber(b, 5);
			sp.addNumber(c);
			sp.addNumber(d);
			sp.addNumber(99);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Span: " << std::endl;
		printSpan(sp);
		std::cout << std::endl;
		try {
			std::cout << "\nShortest: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		//std::cout << sp[2000] << std::endl;
	}
	std::cout << "\n\t*** BIG NUMBERS TESTS ***\n" << std::endl;
	{
		Span sp = Span(10000);

		try {
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MIN);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Span: " << std::endl;
		printSpan(sp);
		std::cout << std::endl;
		std::cout << "Span max size: " << sp.getMaxSize() << std::endl;
		try {
			for (unsigned int i = 0; i < sp.getMaxSize(); i++)
			sp.addNumber(42);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "\nShortest: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\t*** EXCEPTIONS TESTS ***\n" << std::endl;
	{
		Span sp = Span(1);

		try {
			sp.addNumber(-1);
			sp.addNumber(0);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Span: " << std::endl;
		printSpan(sp);
		std::cout << std::endl;
		try {
			std::cout << "\nShortest: " << sp.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}

static void	printSpan(const Span& sp) {

	for (unsigned int i = 0; i < sp.getSize(); i++) {
		std::cout << sp.getPtr()[i];
		if (i < sp.getSize() - 1)
			std::cout << ", ";
	}
	
}
