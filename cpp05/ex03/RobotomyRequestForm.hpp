/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:28:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <random>

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator= (const RobotomyRequestForm& other);
	~RobotomyRequestForm(void);

	const std::string&	getTarget(void) const;

	void	execute(Bureaucrat const & executor) const override;

private:

	RobotomyRequestForm(void);
	bool	_randomize(void) const;

	std::string			_target;
};
