/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/06 20:49:43 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat {

public:

	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator= (const Bureaucrat& other);
	~Bureaucrat(void);

	const std::string&	getName(void) const;
	const int&			getGrade(void) const;

	void	incrementGrade(int num);
	void	decrementGrade(int num);

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
class	GradeTooHighException : public std::exception {

public:

	GradeTooHighException() {};
	~GradeTooHighException() {};

	virtual const char*	what(void) noexcept(true) const override;

private:

	static const std::string	_msg = "Grade is too high.";
};
