/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	Form(const std::string name, const int sign, const int exec);
	Form(const Form& other);
	Form&	operator= (const Form& other);
	~Form(void);

	const std::string&	getName(void) const;
	const bool&			getIsSigned(void) const;
	const int&			getGradeToSign(void) const;
	const int&			getGradeToExecute(void) const;

	void	beSigned(const Bureaucrat& bureaucrat);

	class	GradeTooHighException;
	class	GradeTooLowException;

private:

	Form(void);
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	static const int	_maxGrade = 1;
	static const int	_minGrade = 150;
};

class	Form::GradeTooHighException : public std::exception {
public:
	GradeTooHighException() {};
	~GradeTooHighException() {};
	const char*	what(void) const noexcept override;
private:
	static const std::string	_msg;
};

class	Form::GradeTooLowException : public std::exception {
public:
	GradeTooLowException() {};
	~GradeTooLowException() {};
	const char*	what(void) const noexcept override;
private:
	static const std::string	_msg;
};

std::ostream&	operator<< (std::ostream& output, const Form& other);
