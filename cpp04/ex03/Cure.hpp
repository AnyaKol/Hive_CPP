/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:20:44 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 17:20:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class	Cure : public virtual AMateria
{

	public:
		Cure(void);
		Cure(const Cure& other);
		Cure&	operator= (const Cure& other);
		~Cure(void);

		AMateria*	clone() const override;
		void		use(ICharacter& target) override;

};
