/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/07 21:34:40 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <climits>

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTOR TESTS ***" << std::endl;
	{
		//Bureaucrat* const d = new Bureaucrat();
		Bureaucrat* const d = new Bureaucrat("Denis", 1);

		try {
			std::cout << "\ntry:" << std::endl;
			Bureaucrat a("Adam", 120);
			Bureaucrat b(a);
			//Bureaucrat c;
			Bureaucrat c("Bob", 150);
			c = b;
    
			*d = c;
			std::cout << std::endl;
    
			std::cout << "A: " << a << std::endl;
			a.incrementGrade(15);
			std::cout << "A +15: " << a << std::endl;
			a.incrementGrade(0);
			std::cout << "A +0: " << a << std::endl;
			std::cout << "B: " << b << std::endl;
			std::cout << "C: " << c << std::endl;
			c.decrementGrade(30);
			std::cout << "C -30: " << c << std::endl;
			//c.decrementGrade(1);
			//std::cout << "C -1: " << c << std::endl;
			//c.incrementGrade(150);
			//std::cout << "C +150: " << c << std::endl;
			std::cout << "D: " << *d << std::endl;
			d->decrementGrade(1);
			std::cout << "D -1: " << *d << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "\ncatch:" << std::endl;
			std::cout << e.what() << std::endl;
		}

		delete d;
	}

	std::cout << "\n\t*** GRADE OUT OF LIMITS TESTS ***" << std::endl;
	try {
		std::cout << "\ntry A:" << std::endl;
		Bureaucrat a("Adam", INT_MAX);
		std::cout << std::endl;

		std::cout << "A: " << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch A:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\ntry B:" << std::endl;
		Bureaucrat b("Bob", 149);
		std::cout << std::endl;

		std::cout << "B: " << b << std::endl;
		b.decrementGrade(1);
		std::cout << "B -1: " << b << std::endl;
		b.decrementGrade(1);
		std::cout << "B -1: " << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch B:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\ntry C:" << std::endl;
		Bureaucrat* const c = new Bureaucrat("Cris", 0);
		std::cout << std::endl;

		std::cout << "C: " << *c << std::endl;
		std::cout << std::endl;

		delete c;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch C:" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}
