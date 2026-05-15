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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
// arr    //arr 
// arr [] //is an array (so index it)
// * arr [] //of pointers (so dereference them)
// (* arr [])() //to functions taking nothing (so call them with ())
// void (* arr [])() //returning void
AForm*	Intern::makeForm(std::string name, std::string target) {

	AForm*		form;
	std::string	forms[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	AForm* (* funs[3]) (std::string) = {
		makePresidentialPardonForm,
		makeRobotomyRequestForm,
		makeShrubberyCreationForm
	};
	int			i;

	for (i = 0; i < 3; i++) {
		if (forms[i] == name) {
			form = funs[i](target);
			std::cout << "Intern creates" << *form << "." << std::endl;
			return (form);
		}
	}

	throw(Intern::FormNotExistException(name));
}

AForm*	Intern::makePresidentialPardonForm(std::string target) {
	return (new PresidentialPardonForm(target));
}
AForm*	Intern::makeRobotomyRequestForm(std::string target) {
	return (new RobotomyRequestForm(target));
}
AForm*	Intern::makeShrubberyCreationForm(std::string target) {
	return (new ShrubberyCreationForm(target));
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
