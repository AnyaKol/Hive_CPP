/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:59:53 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 16:59:54 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

/* Forward declaration to avoid headers including eac other;
 * can't have AMateria object here, compiler doesn't know it's size; but can
 * have a pointer to this object.
 */
class	AMateria;
// Pure interface, doesn't have any function implementations
class	ICharacter
{
	public:
		virtual	~ICharacter() {}

		virtual std::string const&	getName() const = 0;

		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};
