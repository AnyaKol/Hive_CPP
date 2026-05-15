/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:29:40 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <climits>

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTOR TESTS ***" << std::endl;
	{

		Bureaucrat* const b = new Bureaucrat("Bob", 1);
		Form* const formA = new Form("Application", 120, 1);

		try {
			std::cout << "\ntry:" << std::endl;
			Bureaucrat a("Adam", 121);
			Form formB("Business", 1, 1);
			std::cout << std::endl;
    
			std::cout << "A: " << a << std::endl;
			std::cout << "B: " << *b << std::endl;
			std::cout << "FormA: " << *formA << std::endl;
			std::cout << "FormB: " << formB << std::endl;
			a.signForm(*formA);
			a.incrementGrade(1);
			a.signForm(*formA);
			a.decrementGrade(1);
			a.signForm(*formA);
			b->signForm(formB);
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "\ncatch:" << std::endl;
			std::cout << e.what() << std::endl;
		}

		delete b;
		delete formA;
	}

	std::cout << "\n\t*** GRADE OUT OF LIMITS TESTS ***" << std::endl;
	try {
		std::cout << "\ntry A:" << std::endl;
		Form a("Application", 1, -1);
		std::cout << std::endl;

		std::cout << "A: " << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch A:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\ntry B:" << std::endl;
		Form b("Business", INT_MIN, 100);
		std::cout << std::endl;

		std::cout << "B: " << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch B:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\ntry C:" << std::endl;
		Form* const c = new Form("Coffee", 151, 1);
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
