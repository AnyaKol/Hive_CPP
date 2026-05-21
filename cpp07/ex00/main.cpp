/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:53:51 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/21 10:46:45 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include <iostream>

int main( void ) {

	std::cout << "\n\t*** SUBJECT TESTS ***\n" << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << "\n\t*** ADDITIONAL TESTS ***\n" << std::endl;
	{
		float a = 0.34f;
		float b = 123.3f;

		std::cout << "float" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		char c = '*';
		char d = '+';

		std::cout << "\nchar" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "swap: c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		float* ptr_a = &a;
		float* ptr_b = &b;

		std::cout << "\npointer" << std::endl;
		std::cout << "&a = " << ptr_a << ", &b = " << ptr_b << std::endl;
		::swap(ptr_a, ptr_b);
		std::cout << "swap: &a = " << ptr_a << ", &b = " << ptr_b << std::endl;
		std::cout << "min( &a, &b ) = " << ::min( ptr_a, ptr_b ) << std::endl;
		std::cout << "max( &a, &b ) = " << ::max( ptr_a, ptr_b ) << std::endl << std::endl;
	}

	return (0);
}
