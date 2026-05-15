/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:34:18 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default constructor - should not be used
Form::Form(void) : Form("DefaultName", 150, 150) {}

// Constructor with parameter
Form::Form(const std::string name, const int sign, const int exec)
: _name(name), _gradeToSign(sign), _gradeToExecute(exec) {

	if (sign < _maxGrade || exec < _maxGrade)
		throw (Form::GradeTooHighException());
	if (sign > _minGrade || exec > _minGrade)
		throw (Form::GradeTooLowException());

	this->_isSigned = false;
	std::cout << *this << ": Form created." << std::endl;
}

// Copy constructor
Form::Form(const Form& other)
: _name(other._name),
_gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute) {}

// Copy assignment operator overload
Form&	Form::operator= (const Form& other) {

	if (this != &other) {
		std::cout << "Nothing to copy." << std::endl;
	}

	return (*this);
}

// Destructor
Form::~Form(void) {
	std::cout << *this << ": Form deleted." << std::endl;
}

// Getters
const std::string&	Form::getName(void) const {
	return (this->_name);
}

const bool&	Form::getIsSigned(void) const {
	return (this->_isSigned);
}

const int&	Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

const int&	Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

// Insertion operator overload
std::ostream&	operator<< (std::ostream& output, const Form& other) {
	output << other.getName() << " [ " << other.getGradeToSign() << " | "
		<< other.getGradeToExecute() << " ], signed [ ";
	if (other.getIsSigned())
		output << "YES";
	else
		output << "NO";
	output << " ]";

	return (output);
}

// Form function
void	Form::beSigned(const Bureaucrat& bureaucrat) {

	if (this->_isSigned == true) {
		std::cout << *this << ": Form is already signed." << std::endl;
		return ;
	}

	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());

	this->_isSigned = true;
}

// Exceptions
const std::string Form::GradeTooHighException::_msg
	= "Grade is too high.";

const char*	Form::GradeTooHighException::what(void) const noexcept {
	return (this->_msg.c_str());
}

const std::string Form::GradeTooLowException::_msg
	= "Grade is too low.";

const char*	Form::GradeTooLowException::what(void) const noexcept {
	return (this->_msg.c_str());
}
