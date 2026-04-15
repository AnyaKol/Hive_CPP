/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 22:04:13 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	{
        Fixed		a;
		Fixed const	b( 10 );
		Fixed const	c( 42.42f );
        Fixed const	d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}

	std::cout << "\n *** Additional tests ***\n" << std::endl;

	{
		Fixed a(-123.42f);
		std::cout << "Fixed a(-123.42f):"
			<< "\nraw bits: " << a.getRawBits()
			<< "\nto Int: " << a.toInt()
			<< "\nto Float: " << a.toFloat()
			<< "\na <<: " << a << std::endl;
	}

	return 0;
}
