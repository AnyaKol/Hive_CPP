/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:38:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 20:57:29 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

public:

	HumanB(std::string name);
	~HumanB(void);

	void	attack(void);
	void	setWeapon(Weapon& weapon);

private:

	std::string	name;
	Weapon*		weapon;

};

#endif
