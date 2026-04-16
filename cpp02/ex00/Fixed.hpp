/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 21:17:15 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 19:11:11 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class	Fixed {

public:

	Fixed(void);
	Fixed(const Fixed& other);
	Fixed& operator= (const Fixed& other);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int					_rawBits;
	static const int	_bits = 8;

};
