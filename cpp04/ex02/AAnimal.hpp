/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 16:50:20 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal {

public:

	AAnimal(void);
	AAnimal(const AAnimal& other);
	AAnimal&	operator= (const AAnimal& other);
	virtual ~AAnimal(void);

	virtual void		makeSound(void) const = 0;
	const std::string&	getType(void) const;

protected:

	std::string	_type;

};
