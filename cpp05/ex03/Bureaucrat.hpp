/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:27:40 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	AForm;

class	Bureaucrat {

public:

	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator= (const Bureaucrat& other);
	~Bureaucrat(void);

	const std::string&	getName(void) const;
	const int&			getGrade(void) const;

	void	incrementGrade(int num);
	void	decrementGrade(int num);
	void	signForm(AForm& form) const;
	void	executeForm(AForm const & form) const;

	class	GradeTooHighException;
	class	GradeTooLowException;

private:

	Bureaucrat(void);
	const std::string	_name;
	int					_grade;

	static const int	_maxGrade = 1;
	static const int	_minGrade = 150;
};

/* noexcept 
 * C++11: Specifies whether a function might throw exceptions.
 */
class	Bureaucrat::GradeTooHighException : public std::exception {
public:
	GradeTooHighException() {};
	~GradeTooHighException() {};
	const char*	what(void) const noexcept override;
private:
	static const std::string	_msg;
};

class	Bureaucrat::GradeTooLowException : public std::exception {
public:
	GradeTooLowException() {};
	~GradeTooLowException() {};
	const char*	what(void) const noexcept override;
private:
	static const std::string	_msg;
};

std::ostream&	operator<< (std::ostream& output, const Bureaucrat& other);
