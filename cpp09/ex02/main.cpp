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
		base.add(argv[i]);
	}

	std::cout << "Before:\t";
	base.printSequence();

	base.sort();

	std::cout << "\nAfter:\t";
	base.printSequence();
	std::cout << std::endl;

	std::cout << "Time to process a range of " << base.getSize()
		<< " elements with std::vector: " << base.getTimeVector() << "us\n"
		<< "Time to process a range of " << base.getSize()
		<< " elements with std::deque: " << base.getTimeDeque() << "us" << std::endl;

	return (0);
}
