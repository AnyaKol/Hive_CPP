/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/05 19:53:06 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor - should not be used
Bureaucrat::Bureaucrat(void) : Bureaucrat("DefaultName", 150) {
	std::cout << "Default constructor." << std::endl;
}

// Constructor with parameters
Bureaucrat::Bureaucrat(std::string name, int grade) {

	this->_name	= name;
	this->_grade = grade;

	std::cout << this->_name << ", " << this->_grade << " hired." << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << "Copying " << other._name << ", " << other._grade << "..."
		<< std::endl;

	*this = other;
}

// Copy assignment operator overload
Bureaucrat&	Bureaucrat::operator= (const Bureaucrat& other) {

	if (this != &other) {
		this->_name	= other.name;
		this->_grade = other.grade;
	}

	std::cout << this->_name << ", " << this->_grade << " copied." << std::endl;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
	std::cout << this->_name << ", " << this->_grade << " fired~" << std::endl;
}

// Getters
const std::string&	Bureaucrat::getName(void) const {
	return (this->_name);
}

const int&	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

// Grade modification
void	incrementGrade(int num) {
	this->_grade--;
}

void	decrementGrade(int num) {
	this->grade++;
}
