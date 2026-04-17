/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 18:58:29 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap&	operator= (const ScavTrap& other);
	~ScavTrap(void);

	void	attack(const std::string& target) override;
	void	takeDamage(unsigned int amount) override;
	void	beRepaired(unsigned int amount) override;

	void	guardGate(void);

private:

	ScavTrap(void);

	void	_announce(void) const override;
	bool	_checkDeath(void) const override;
	bool	_checkEnergy(void) const override;

};
