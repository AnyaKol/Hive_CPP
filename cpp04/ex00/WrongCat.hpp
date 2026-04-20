/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:28:08 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 14:28:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal {

public:

	WrongCat(void);
	WrongCat(const WrongCat& other);
	WrongCat&	operator= (const WrongCat& other);
	~WrongCat(void);

	void	makeSound(void) const;

};
