/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 16:50:20 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {

public:

	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator= (const ClapTrap& other);
	~ClapTrap(void);

	virtual void	attack(const std::string& target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);

protected:

	ClapTrap(void);

	virtual void	_announce(void) const;
	virtual bool	_checkDeath(void) const;
	virtual bool	_checkEnergy(void) const;

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};
