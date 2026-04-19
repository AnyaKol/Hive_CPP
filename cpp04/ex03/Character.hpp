/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:51:08 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 19:42:25 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

typedef struct	t_AMateria {
	AMateria*	data;
	t_AMateria*	next;
} t_AMateria;

class	Character : virtual public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		t_AMateria*	_discarded;

		void	_discardMateria(AMateria *m);

	public:
		Character(void);
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator= (const Character& other);
		~Character();

		std::string const&	getName() const override;

		void	equip(AMateria* m) override;
		void	unequip(int idx) override;
		void	use(int idx, ICharacter& target) override;
};

std::ostream&	operator<< (std::ostream& output, const Character& other);
