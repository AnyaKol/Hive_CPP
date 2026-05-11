/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/07 20:56:44 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor - should not be used
Bureaucrat::Bureaucrat(void) : Bureaucrat("DefaultName", 150) {
	std::cout << "Default constructor." << std::endl;
}

// Constructor with parameters
Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name), _grade(grade) {

	if (grade < _maxGrade)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > _minGrade)
		throw (Bureaucrat::GradeTooLowException());

	std::cout << *this << " hired." << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
: _name(other._name), _grade(other._grade) {

	std::cout << "Copying " << other << "." << std::endl;
}

// Copy assignment operator overload
Bureaucrat&	Bureaucrat::operator= (const Bureaucrat& other) {

	if (this != &other) {
		this->_grade = other._grade;
	}

	std::cout << *this << " copied." << std::endl;
	return (*this);
}

// Insertion operator overload
std::ostream&	operator<< (std::ostream& output, const Bureaucrat& other) {
	output << other.getName() << ", bureaucrat grade  " << other.getGrade()
		<< ".";

	return (output);
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
	std::cout << *this << " fired~" << std::endl;
}

// Getters
const std::string&	Bureaucrat::getName(void) const {
	return (this->_name);
}

const int&	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

// Grade modification
void	Bureaucrat::incrementGrade(int num) {

	if (this->_grade - num < this->_maxGrade)
		throw (Bureaucrat::GradeTooHighException());

	this->_grade -= num;
}

void	Bureaucrat::decrementGrade(int num) {

	if (this->_grade + num > this->_minGrade)
		throw (Bureaucrat::GradeTooLowException());

	this->_grade += num;
}

// Exceptions
const std::string Bureaucrat::GradeTooHighException::_msg
	= "Grade is too high.";

const char*	Bureaucrat::GradeTooHighException::what(void) const noexcept {
	return (this->_msg.c_str());
}

const std::string Bureaucrat::GradeTooLowException::_msg
	= "Grade is too low.";

const char*	Bureaucrat::GradeTooLowException::what(void) const noexcept {
	return (this->_msg.c_str());
}
