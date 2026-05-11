/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:17:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default constructor
Intern::Intern(void) {
	std::cout << "Some intern hired." << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& other) {
	*this = other;

	std::cout << "Copy of some intern hired." << std::endl;
}

// Copy assignment operator overload
Intern&	Intern::operator= (const Intern& other) {

	if (this != &other) {
		std::cout << "Some intern copied." << std::endl;
	}

	return (*this);
}

// Destructor
Intern::~Intern(void) {
	std::cout << "Some intern fired~" << std::endl;
}

// Intern function
AForm*	Intern::makeForm(std::string name, std::string target) {

	AForm*		form;
	std::string	forms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	int			i;

	for (i = 0; i < 3; i++) {
		if (forms[i] == name)
			break ;
	}

	switch (i) {
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw(Intern::FormNotExistException(name));
	}

	std::cout << "Intern creates" << *form << "." << std::endl;
	return (form);
}

// Exception
// Form not exist
// Constructor with parameter
Intern::FormNotExistException::FormNotExistException(std::string name)
: _msg("Form name '" + name + "' doesn't exist.") {}

const char*	Intern::FormNotExistException::what(void) const noexcept
{
	return (this->_msg.c_str());
}
