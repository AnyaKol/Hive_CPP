/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:31:03 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 19:12:04 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class	MateriaSource : virtual public IMateriaSource
{
	private:
		AMateria*		_memory[4];
		unsigned int	_lastIdx;

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator= (const MateriaSource& other);
		~MateriaSource();

		unsigned int const&	_getLastIndex() const;

		void		learnMateria(AMateria*) override;
		AMateria*	createMateria(std::string const & type) override;
};

std::ostream&	operator<< (std::ostream& output, const MateriaSource& other);
