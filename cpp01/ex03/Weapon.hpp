/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:38:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 20:27:09 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon {

public:

	Weapon(std::string type);
	~Weapon(void);

	const std::string&	getType(void);
	void				setType(std::string type);

private:

	std::string	_type;

};
