/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:51:08 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 17:51:11 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class	Character : virtual public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];

	public:
		Character(void);
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator= (const Character& other);
		~Character();

		std::string const&	getName() const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

std::ostream&	operator<< (std::ostream& output, const Character& other);
