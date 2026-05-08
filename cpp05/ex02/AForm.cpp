/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:34:18 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor - should not be used
AForm::AForm(void) : AForm("DefaultName", 1, 1) {}

// Constructor with parameters
AForm::AForm(const std::string name, const int sign, const int exec)
: _name(name), _gradeToSign(sign), _gradeToExecute(exec) {

	if (sign < _maxGrade || exec < _maxGrade)
		throw (AForm::GradeTooHighException());
	if (sign > _minGrade || exec > _minGrade)
		throw (AForm::GradeTooLowException());

	this->_isSigned = false;
	std::cout << *this << ": AForm created." << std::endl;
}

// Copy constructor
AForm::AForm(const AForm& other)
: _name(other._name),
_gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute) {}

// Copy assignment operator overload
AForm&	AForm::operator= (const AForm& other) {

	if (this != &other) {
		std::cout << "Nothing to copy." << std::endl;
	}

	return (*this);
}

// Destructor
AForm::~AForm(void) {
	std::cout << *this << ": AForm deleted." << std::endl;
}

// Getters
const std::string&	AForm::getName(void) const {
	return (this->_name);
}

const bool&	AForm::getIsSigned(void) const {
	return (this->_isSigned);
}

const int&	AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

const int&	AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

// Insertion operator overload
std::ostream&	operator<< (std::ostream& output, const AForm& other) {
	output << other.getName() << " [ " << other.getGradeToSign() << " | "
		<< other.getGradeToExecute() << " ], signed [ ";
	if (other.getIsSigned())
		output << "YES";
	else
		output << "NO";
	output << " ]";

	return (output);
}

// AForm function
void	AForm::beSigned(const Bureaucrat& bureaucrat) {

	if (this->_isSigned == true) {
		std::cout << *this << ": AForm is already signed." << std::endl;
		return ;
	}

	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());

	this->_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const {

	if (this->_isSigned == false)
		throw (AForm::NotSignedException());

	if (executor.getGrade() > this->_gradeToExecute)
		throw (AForm::GradeTooLowException());
}

// Exceptions
// Grade too high
const std::string AForm::GradeTooHighException::_msg
	= "Grade is too high.";

const char*	AForm::GradeTooHighException::what(void) const noexcept {
	return (this->_msg.c_str());
}

// Grade too low
AForm::GradeTooLowException::GradeTooLowException() {
	this->_msg = "Grade is too low.";
};

const char*	AForm::GradeTooLowException::what(void) const noexcept {
	return (this->_msg.c_str());
}

void	AForm::GradeTooLowException::addFormType(const std::string& type) {
	this->_msg = type + ": " + this->_msg;
}

// Form is not signed
const std::string AForm::NotSignedException::_msg
	= "Form is not signed.";

const char*	AForm::NotSignedException::what(void) const noexcept {
	return (this->_msg.c_str());
}
