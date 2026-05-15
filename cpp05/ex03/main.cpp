/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 22:15:52 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <memory>

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTOR TESTS ***" << std::endl;
	{

		Intern* const a = new Intern();

		try {
			std::cout << "\ntry:" << std::endl;
			Intern b;
			Intern c(b);
			b = *a;
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "\ncatch:" << std::endl;
			std::cout << e.what() << std::endl;
		}

		delete a;
	}

	std::cout << "\n\t*** INTERN TESTS ***" << std::endl;
	try {
		std::cout << "\ntry A:" << std::endl;
		Intern i;
		Bureaucrat a("Alan", 110);
		Bureaucrat b("Berry", 1);

		std::unique_ptr<AForm> formA( 
			i.makeForm("presidential pardon", "PardonTarget") );
		std::unique_ptr<AForm> formB(
			i.makeForm("robotomy request", "RobotTarget") );
		std::unique_ptr<AForm> formC(
			i.makeForm("shrubbery creation", "ShrubTarget") );
		std::cout << std::endl;

		a.signForm(*formA);
		a.signForm(*formB);
		a.signForm(*formC);
		std::cout << std::endl;

		b.signForm(*formA);
		b.signForm(*formB);
		b.signForm(*formC);
		std::cout << std::endl;

		a.executeForm(*formA);
		a.executeForm(*formB);
		a.executeForm(*formC);
		std::cout << std::endl;

		b.executeForm(*formA);
		b.executeForm(*formB);
		b.executeForm(*formC);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch A:" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\ntry B:" << std::endl;
		Intern i;
		Bureaucrat b("Berry", 1);

		std::unique_ptr<AForm> formA(
			i.makeForm("presidential pardon", "PardonTarget") );
		std::unique_ptr<AForm> formB(
			i.makeForm("shrubberycreation", "ShrubTarget2") );
		std::cout << std::endl;

		b.signForm(*formA);
		b.signForm(*formB);
		std::cout << std::endl;

		b.executeForm(*formA);
		b.executeForm(*formB);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch B:" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}
