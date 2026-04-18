/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
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

class Animal {

public:

	Animal(void);
	Animal(std::string name);
	Animal(const Animal& other);
	Animal&	operator= (const Animal& other);
	virtual ~Animal(void);

	virtual void		makeSound(void) const;
	const std::string&	getType(void) const;
	const std::string&	getName(void) const;
	void				setName(const std::string& name);

protected:

	Animal(std::string type, std::string name);

	void	_announce(void) const;

	std::string	_type;
	std::string	_name;

};
