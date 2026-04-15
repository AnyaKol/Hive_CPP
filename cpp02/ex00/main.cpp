/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 19:43:43 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
    
		c = b;
    
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}

	std::cout << "\n *** Additional tests ***\n" << std::endl;

	{
		Fixed a;
		std::cout << "Fixed a: " << a.getRawBits() << std::endl;

		a.setRawBits(34);
		std::cout << "a.setRawBits(34): " << a.getRawBits() << std::endl;

		Fixed b;
		std::cout << "Fixed b: " << b.getRawBits() << std::endl;

		Fixed c(a);
		std::cout << "Fixed c(a): " << c.getRawBits() << std::endl;

		Fixed d;
		std::cout << "Fixed d: " << d.getRawBits() << "\n" << std::endl;

		c = b = a;
		std::cout << "c = b = a\nb: " << b.getRawBits()
			<< "\nc: " << c.getRawBits() << "\n" << std::endl;

		Fixed* ptr = &d;
		d = *ptr;
		std::cout << "Fixed* ptr = &d\nd = *ptr\nd: " << d.getRawBits()
			<< std::endl;
		ptr->setRawBits(120);
		std::cout << "*ptr.setRawBits(120);\nptr: " << ptr->getRawBits()
			<< "\nd: " << d.getRawBits() << "\n" << std::endl;
	}

	return 0;
}
