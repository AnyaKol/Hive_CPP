/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:27:51 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 14:27:54 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal {

public:

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&	operator= (const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	void				makeSound(void) const;
	const std::string&	getType(void) const;

protected:

	std::string	_type;

};
