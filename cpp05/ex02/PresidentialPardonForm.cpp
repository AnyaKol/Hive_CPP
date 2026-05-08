/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:34:18 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor - should not be used
PresidentialPardonForm::PresidentialPardonForm(void)
: PresidentialPardonForm("DefaultTarget") {}

// Constructor with parameter
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {

	std::cout << *this << ": PresidentialPardonForm created." << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&
other) : AForm("PresidentialPardonForm", other.getGradeToSign(),
other.getGradeToExecute()), _target(other._target) {}

// Copy assignment operator overload
PresidentialPardonForm&	PresidentialPardonForm::operator=
(const PresidentialPardonForm& other) {

	if (this != &other) {
		this->_target = other._target;
	}

	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << *this << ": PresidentialPardonForm deleted." << std::endl;
}

// Getter
const std::string&	PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}

// PresidentialPardonForm function
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	try {
		AForm::execute(executor);
	}
	catch (AForm::NotSignedException &e) {
		throw ;
	}
	catch (AForm::GradeTooLowException &e) {
		e.addFormType("PresidentialPardonForm");
		throw ;
	}

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}

