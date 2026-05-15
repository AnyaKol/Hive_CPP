/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:28:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	Bureaucrat;

class	AForm {

public:

	AForm(const std::string name, const int sign, const int exec);
	AForm(const AForm& other);
	AForm&	operator= (const AForm& other);
	virtual ~AForm(void) = 0;

	const std::string&	getName(void) const;
	const bool&			getIsSigned(void) const;
	const int&			getGradeToSign(void) const;
	const int&			getGradeToExecute(void) const;

	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const;

	class	GradeTooHighException;
	class	GradeTooLowException;
	class	NotSignedException;

protected:

	static const int	_maxGrade = 1;
	static const int	_minGrade = 150;

private:

	AForm(void);
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

class	AForm::GradeTooHighException : public std::exception {
public:
	GradeTooHighException() {};
	~GradeTooHighException() {};
	const char*	what(void) const noexcept override;
private:
	static const std::string	_msg;
};

class	AForm::GradeTooLowException : public std::exception {
public:
	GradeTooLowException();
	~GradeTooLowException() {};
	const char*	what(void) const noexcept override;
	void		addFormType(const std::string& type);
private:
	std::string	_msg;
};

class	AForm::NotSignedException : public std::exception {
public:
	NotSignedException() {};
	~NotSignedException() {};
	const char*	what(void) const noexcept override;
private:
	static const std::string	_msg;
};

std::ostream&	operator<< (std::ostream& output, const AForm& other);
