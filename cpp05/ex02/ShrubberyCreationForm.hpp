/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:28:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <filesystem>

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator= (const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);

	const std::string&	getTarget(void) const;

	void	execute(Bureaucrat const & executor) const override;

private:

	ShrubberyCreationForm(void);

	std::string			_target;
};
