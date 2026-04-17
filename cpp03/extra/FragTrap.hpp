/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 19:05:04 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap(const std::string name);
	FragTrap(const FragTrap& other);
	FragTrap&	operator= (const FragTrap& other);
	~FragTrap(void);

	void	attack(const std::string& target) override;
	void	takeDamage(unsigned int amount) override;
	void	beRepaired(unsigned int amount) override;

	void	highFivesGuys(void);

private:

	FragTrap(void);

	void	_announce(void) const override;
	bool	_checkDeath(void) const override;
	bool	_checkEnergy(void) const override;

};
