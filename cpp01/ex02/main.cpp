/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:18:53 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/13 19:31:25 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR;
	std::string&	stringREF = str;

	stringPTR = &str;
	std::cout << "The address of the string variable: " << &str << std::endl;
	std::cout << "The address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
