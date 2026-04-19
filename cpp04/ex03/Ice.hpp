/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:20:28 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 17:20:29 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class	Ice : public virtual AMateria
{

	public:
		Ice(void);
		Ice(const Ice& other);
		Ice&	operator= (const Ice& other);
		~Ice(void);

		AMateria*	clone() const override;
		void		use(ICharacter& target) override;

};
