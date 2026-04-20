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
	Animal(std::string name);// Helper
	Animal(const Animal& other);
	Animal&	operator= (const Animal& other);
	virtual ~Animal(void);

	virtual void		makeSound(void) const;
	const std::string&	getType(void) const;
	const std::string&	getName(void) const;// Helper
	void				setName(const std::string& name);// Helper

protected:

	Animal(std::string type, std::string name);// Helper

	void	_announce(void) const;// Helper

	std::string	_type;
	std::string	_name;// Helper

};
