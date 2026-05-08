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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {

	std::cout << "\n\t*** CONSTRUCTOR TESTS ***" << std::endl;
	{

		Bureaucrat* const a = new Bureaucrat("Adam", 1);
		PresidentialPardonForm* const formA = new PresidentialPardonForm("TargetA");
		RobotomyRequestForm* const formB = new RobotomyRequestForm("TargetB");
		ShrubberyCreationForm* const formC = new ShrubberyCreationForm("TargetC");

		try {
			std::cout << "\ntry:" << std::endl;
			Bureaucrat b("Bob", 150);
			PresidentialPardonForm formD("TargetD");
			RobotomyRequestForm formE("TargetE");
			ShrubberyCreationForm formF("TargetF");
			std::cout << std::endl;

			std::cout << "A: " << *a << std::endl;
			std::cout << "B: " << b << std::endl;
			std::cout << "FormA: " << *formA << std::endl;
			std::cout << "FormB: " << *formB << std::endl;
			std::cout << "FormC: " << *formC << std::endl;
			std::cout << "FormD: " << formD << std::endl;
			std::cout << "FormE: " << formE << std::endl;
			std::cout << "FormF: " << formF << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "\ncatch:" << std::endl;
			std::cout << e.what() << std::endl;
		}

		delete a;
		delete formA;
		delete formB;
		delete formC;
	}

	std::cout << "\n\t*** FORMS TESTS ***" << std::endl;
	try {
		std::cout << "\ntry A:" << std::endl;
		Bureaucrat a("Alan", 110);
		Bureaucrat b("Berry", 1);
		PresidentialPardonForm formA("PardonTarget");
		RobotomyRequestForm formB("RobotTarget");
		ShrubberyCreationForm formC("ShrubTarget");
		std::cout << std::endl;

		a.signForm(formA);
		a.signForm(formB);
		a.signForm(formC);
		b.signForm(formA);
		b.signForm(formB);
		b.signForm(formC);
		a.executeForm(formA);
		a.executeForm(formB);
		a.executeForm(formC);
		b.executeForm(formA);
		for (int i = 0; i < 10; i++)
			b.executeForm(formB);
		b.executeForm(formC);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\ncatch A:" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}
