/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:58:31 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 18:52:25 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie {

public:

	Zombie( void );
	~Zombie( void );

	void	announce( void );
	void	setName( const std::string& name );

private:

	std::string	_name;

};

Zombie*	zombieHorde( int N, std::string name );
