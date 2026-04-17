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

	bool	operator> (const Fixed& other) const;
	bool	operator< (const Fixed& other) const;
	bool	operator>= (const Fixed& other) const;
	bool	operator<= (const Fixed& other) const;
	bool	operator== (const Fixed& other) const;
	bool	operator!= (const Fixed& other) const;

	Fixed	operator+ (const Fixed& other) const;
	Fixed	operator- (const Fixed& other) const;
	Fixed	operator* (const Fixed& other) const;
	Fixed	operator/ (const Fixed& other) const;

	
	Fixed	operator++ (int);
	Fixed&	operator++ ();
	Fixed	operator-- (int);
	Fixed&	operator-- ();

	static Fixed&	max (const Fixed& a, const Fixed& b);
	static Fixed&	max (Fixed& a, Fixed& b);
	static Fixed&	min (const Fixed& a, const Fixed& b);
	static Fixed&	min (Fixed& a, Fixed& b);

private:

	int					_rawBits;
	static const int	_bits = 8;

};

std::ostream& operator<< (std::ostream& output, const Fixed& other);
