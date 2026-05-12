/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/12 10:01:04 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Default constructor - should not be used
ScalarConverter::ScalarConverter(void) {}

// Copy constructor - should not be used
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

// Copy assignment operator overload
ScalarConverter&	ScalarConverter::operator= (const ScalarConverter&) {

	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void) {}

// ScalarConverter function
void	ScalarConverter::convert(std::string val) {

	std::string	charStr = "";
	std::string	intStr = "";
	std::string	floatStr = "";
	std::string	doubleStr = "";

	if (isSpecial(val)) {
		return ;
	}

	if (val.length() == 1) {
		char(val[0]);
	} else {
		try {
			int ascii = std::stoi(val);

			if (ascii >= 32 && ascii <= 126) {
				std::cout << char(ascii);
			}
			else if ((ascii >= 0 && ascii < 32) || ascii == 127) {
				std::cout << "Non displayable";
			}
			else {
				std::cout << "Impossible";
			}
		}
		catch (std::exception &e) {
			std::cout << "Impossible";
		}
	}

	std::cout << "\nint: ";
	try {
		std::cout << std::stoi(val);
	}
	catch (std::invalid_argument &e) {
		std::cout << "Impossible";
	}
	catch (std::out_of_range &e) {
		std::cout << "Out of range";
	}

	std::cout << "\nfloat: ";
	try {
		std::cout << std::stof(val);
	}
	catch (std::invalid_argument &e) {
		std::cout << "Impossible";
	}
	catch (std::out_of_range &e) {
		std::cout << "Out of range";
	}

	std::cout << "\ndouble: ";
	try {
		std::cout << std::stod(val);
	}
	catch (std::invalid_argument &e) {
		std::cout << "Impossible";
	}
	catch (std::out_of_range &e) {
		std::cout << "Out of range";
	}

	std::cout << "char: " << charStr
		<< "\nint: " << intStr
		<< "\nfloat: " << floatStr
		<< "\ndouble: " << doubleStr << std::endl;
}

static bool	isSpecial(std::string val) {

	std::string	specials[6] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
	};

	for (int i = 0; i < 6; i++) {
		if (specials[i] == val) {
			return (true);
		}
	}
	return (false);
}


