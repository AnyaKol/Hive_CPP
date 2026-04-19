/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:46:27 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 16:46:28 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# include "ICharacter.hpp"

class	AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(const AMateria& other);
		AMateria(std::string const& type);
		AMateria&	operator= (const AMateria& other);
		virtual ~AMateria(void) {}

		std::string const& getType() const; //Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

std::ostream&	operator<< (std::ostream& output, const AMateria& other);