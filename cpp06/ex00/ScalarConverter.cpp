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

#include <iostream>
#include <limits>

// Copy constructor - should not be used
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

// Copy assignment operator overload
ScalarConverter&	ScalarConverter::operator= (const ScalarConverter&) {

	return (*this);
}

// ScalarConverter function
struct types{
	char	c;
	int		i;
	float	f;
	double	d;
};

const std::string impos = "Impossible";
const std::string nonDispl = "Non displayable";
const std::string outRange = "Out of range";

struct display{
	std::string	charStr = impos;
	std::string	intStr = impos;
	std::string	floatStr = impos;
	std::string	doubleStr = impos;
};

static bool	isSpecial(const std::string& val, types& Types, display& Display);
static bool	isChar(const std::string& val, types& Types, display& Display);
static void	printResult(const display& Display);

void	ScalarConverter::convert(const std::string& val) {

	types Types;
	display Display;
	bool (* funcs[])(const std::string& val, types& Types, display& Display) = {
		isSpecial,
		isChar,

	};


	if (isSpecial(val, Types, Display)) {
		printResult( const_cast<const display&>(Display) );
		return ;
	}
	if (isChar(val, Types, Display)) {
		printResult( const_cast<const display&>(Display) );
		return;
	}
	if (isInt(val, Types, Display)) {
		printResult( const_cast<const display&>(Display) );
		return;
	}
	printResult( const_cast<const display&>(Display) );

	try {
		std::cout << std::stof(val);
	}
	catch (std::invalid_argument &e) {
		std::cout << impos;
	}
	catch (std::out_of_range &e) {
		std::cout << outRange;
	}

	try {
		std::cout << std::stod(val);
	}
	catch (std::invalid_argument &e) {
		std::cout << impos;
	}
	catch (std::out_of_range &e) {
		std::cout << outRange;
	}
}

static bool	isSpecial(const std::string& val, types& Types, display& Display) {

	int			i;
	std::string	specials[6] = {
		"-inff",
		"-inf",
		"+inff",
		"+inf",
		"nanf",
		"nan"
	};

	for (i = 0; i < 6; i++) {
		if (specials[i] == val)
			break;
	}

	switch (i) {
		case 0:
			Types.f = std::numeric_limits<float>::infinity();
			Types.f = -Types.f;
			break;
		case 1:
			Types.d = std::numeric_limits<double>::infinity();
			Types.d = -Types.d;
			break;
		case 2:
			Types.f = std::numeric_limits<float>::infinity();
			break;
		case 3:
			Types.d = std::numeric_limits<double>::infinity();
			break;
		case 4:
			Types.f = std::numeric_limits<float>::quiet_NaN();
			break;
		case 5:
			Types.d = std::numeric_limits<double>::quiet_NaN();
			break;
		case 6:
			return (false);
	}

	if (i % 2 == 0) {
		Types.d = static_cast<double>(Types.f);
	} else {
		Types.f = static_cast<float>(Types.d);
	}
	Display.floatStr = std::to_string(Types.f);
	Display.doubleStr = std::to_string(Types.d);

	return (true);
}

// From subject:
// If input is a char - it is displayable.
static bool	isChar(const std::string& val, types& Types, display& Display) {

	if ( val.length() == 1 && !isdigit( char(val[0]) ) ) {
		Types.c = static_cast<char>(val[0]);
		Display.charStr = static_cast<std::string>(&Types.c);
		return (true);
	}
	return (false);
}

// std::string::npos is returned if nothing was found.
static bool	isInt(const std::string& val, types& Types, display& Display) {

	std::string::size_type pos = 0;

	if (val[0] == '-' || val[0] == '+')
		pos = 1;
	if (val.find_first_not_of("1234567890", pos) != std::string::npos)
		return (false);
	try {
		int ascii = std::stoi(val);
		if (ascii >= 32 && ascii <= 126) {
			Types.c = static_cast<char>(ascii);
			Display.charStr = static_cast<std::string>(&Types.c);
		}
		else if ((ascii >= 0 && ascii < 32) || ascii == 127) {
			Display.charStr =  nonDispl;
		}
		return (true);
	}
	catch (std::exception &e) {
		return (false);
	}
}

static void	printResult(const display& Display) {

	std::cout << "char: " << Display.charStr
		<< "\nint: " << Display.intStr
		<< "\nfloat: " << Display.floatStr
		<< "\ndouble: " << Display.doubleStr << std::endl;
}
