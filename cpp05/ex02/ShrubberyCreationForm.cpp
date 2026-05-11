/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:34:18 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor - should not be used
ShrubberyCreationForm::ShrubberyCreationForm(void)
: ShrubberyCreationForm("DefaultTarget") {}

// Constructor with parameter
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {

	std::cout << *this << ": ShrubberyCreationForm created." << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm("ShrubberyCreationForm", other.getGradeToSign(),
other.getGradeToExecute()), _target(other._target) {}

// Copy assignment operator overload
ShrubberyCreationForm&	ShrubberyCreationForm::operator=
(const ShrubberyCreationForm& other) {

	if (this != &other) {
		this->_target = other._target;
	}

	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << *this << ": ShrubberyCreationForm deleted." << std::endl;
}

// Getter
const std::string&	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

// ShrubberyCreationForm function
/* C++17: std::filesystem::exists - checks file existence
 * Can use this:
 * if ( std::filesystem::exists(filename) == false ) ...
 * Not used here.
 */
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	try {
		AForm::execute(executor);
	}
	catch (AForm::NotSignedException &e) {
		throw ;
	}
	catch (AForm::GradeTooLowException &e) {
		e.addFormType("ShrubberyCreationForm");
		throw ;
	}

	std::ofstream	outfile;
	std::string		filename = this->_target + "_shrubbery";

	outfile.open(filename, std::fstream::out | std::fstream::app);
	/* The function open() clears the stream's state flags on success (setting
	 * them to goodbit).
	 * In case of failure, failbit is set, which is detected by fail().
	 */
	if (outfile.fail() == true) {
		throw (ShrubberyCreationForm::OpenFailException(filename));
	}

	outfile
		<< "            # #### ####\n"
		<< "        ### \\/#|### |/####\n"
		<< "       ##\\/#/ \\||/##/_/##/_#\n"
		<< "     ###  \\/###|/ \\/ # ###\n"
		<< "   ##_\\_#\\_\\## | #/###_/_####\n"
		<< "  ## #### # \\ #| /  #### ##/##\n"
		<< "   __#_--###`  |{,###---###-~\n"
		<< "             \\ }{\n"
		<< "              }}{\n"
		<< "              }}{\n"
		<< "              {{}\n"
		<< "        , -=-~{ .-^- _\n"
		<< std::endl;
	outfile.close();
}

// Exception
// File open fail
// Constructor with parameter
ShrubberyCreationForm::OpenFailException::OpenFailException(
	std::string filename) : _msg("Failed to open '" + filename + "'.") {}

const char*	ShrubberyCreationForm::OpenFailException::what(void) const noexcept
{
	return (this->_msg.c_str());
}
