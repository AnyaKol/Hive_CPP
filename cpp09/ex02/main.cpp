/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/07/06 13:10:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main( int argc, char** argv ) {
	PmergeMe	base;

	for (int i = 1; i < argc; i++) {
		try {
			base.add(argv[i]);
		} catch (PmergeMe::NameException &e) {
			PmergeMe::printError(e.what());
		}
	}

	std::cout << "\nBefore:\t";
	PmergeMe::printSequence(base.getSequence());
	std::cout << std::endl;

	try {
		base.sort();
	} catch (PmergeMe::NameException &e) {
		PmergeMe::printError(e.what());
	}

	std::cout << "\nAfter:\t";
	PmergeMe::printSequence(base.getSequence());
	std::cout << std::endl;

	std::cout << "\nTime to process a range of " << base.getSize()
		<< " elements with std::vector: " << base.getTimeVector() << " ms\n"
		<< "Time to process a range of " << base.getSize()
		<< " elements with std::deque: " << base.getTimeDeque() << " ms"
		<< std::endl;

	return (0);
}
