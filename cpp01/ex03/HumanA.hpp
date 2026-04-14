/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:38:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 20:42:00 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void	attack(void);

private:

	std::string	name;
	Weapon&		weapon;

};

#endif
