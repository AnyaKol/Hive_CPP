/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 16:50:20 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

public:

	Intern(void);
	Intern(const Intern& other);
	Intern&	operator= (const Intern& other);
	~Intern(void);

	AForm*	makeForm(std::string name, std::string target);

	class	FormNotExistException;
};

class	Intern::FormNotExistException : public std::exception {
public:
	FormNotExistException(std::string name);
	~FormNotExistException() {};
	const char*	what(void) const noexcept override;
private:
	FormNotExistException();
	const std::string	_msg;
};
