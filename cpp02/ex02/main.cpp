/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 22:26:51 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	{
		Fixed		a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << "\n *** Additional tests ***\n" << std::endl;

	{
		Fixed a(100.42f);
		std::cout << "a: " << a << std::endl;
	
		Fixed b(-0.343f);
		std::cout << "b: " << b << std::endl;

		Fixed c(0);
		std::cout << "c: " << c << std::endl;

		Fixed d;
		d = b;
		std::cout << "d: " << d << std::endl;

		std::cout << "\na > b: " << (a > b) << std::endl;
		std::cout << "\na < c: " << (a < c) << std::endl;
		std::cout << "\na * b: " << (a * b) << std::endl;
		std::cout << "\nb / c: " << (b / c) << std::endl;
		std::cout << "\nd < b: " << (d < b) << std::endl;
		std::cout << "\nd <= b: " << (d <= b) << std::endl;
		std::cout << "\nmax(a, b): " << Fixed::max(a, b) << std::endl;
		std::cout << "\nmin(a, b): " << Fixed::min(a, b) << std::endl;
		std::cout << "\na: " << a << std::endl;
		std::cout << "\na--: " << a-- << std::endl;
		std::cout << "\na: " << a << std::endl;
		std::cout << "\n--a: " << --a << std::endl;
		std::cout << "\na: " << a << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
