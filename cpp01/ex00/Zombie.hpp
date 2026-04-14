/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:58:31 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 18:18:28 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:

	Zombie( void );
	~Zombie( void );

	void	announce( void );
	Zombie*	newZombie( std::string name );
	void	randomChump( std::string name );

private:

	Zombie( std::string name );

	std::string	name;

};

#endif
