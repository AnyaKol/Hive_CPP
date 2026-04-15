/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 21:17:15 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 22:20:00 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {

public:

	Fixed(void);
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed& other);
	Fixed&	operator= (const Fixed& other);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	friend std::ostream& operator<< (std::ostream& output, const Fixed& other);

	bool	operator> (const Fixed& other) const;
	bool	operator< (const Fixed& other) const;
	bool	operator>= (const Fixed& other) const;
	bool	operator<= (const Fixed& other) const;
	bool	operator== (const Fixed& other) const;
	bool	operator!= (const Fixed& other) const;

	float	operator+ (const Fixed& other) const;
	float	operator- (const Fixed& other) const;
	float	operator* (const Fixed& other) const;
	float	operator/ (const Fixed& other) const;

private:

	int					_rawBits;
	static const int	_bits = 8;

};


#endif
