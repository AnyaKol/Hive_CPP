/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/08 18:28:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator= (const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);

	const std::string&	getTarget(void) const;

	void	execute(Bureaucrat const & executor) const override;

private:

	PresidentialPardonForm(void);

	std::string			_target;
};
