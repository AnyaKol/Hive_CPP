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
#include <cctype>
#include <limits>
// Using C++17 for string_view
#include <string_view>

// Copy assignment operator overload
ScalarConverter&	ScalarConverter::operator= (const ScalarConverter&) {

	return (*this);
}

// ScalarConverter function
#pragma region Declarations

enum typeNames{
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

struct types{
	unsigned char	c;
	int				i;
	float			f;
	double			d;
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

static bool	isSpecial(const std::string_view val, types& Types, display& Display);
static bool	isChar(const std::string_view val, types& Types, display& Display);
static bool	isInt(const std::string_view val, types& Types, display& Display);
static bool	isFloat(const std::string_view val, types& Types, display& Display);
static bool	isDouble(const std::string_view val, types& Types, display& Display);
static void	printResult(const display& Display);

#pragma endregion

void	ScalarConverter::convert(const std::string_view val) {

	types	Types;
	display	Display;
	bool (* funcs[])(const std::string_view val, types& Types, display& Display) = {
		isSpecial,
		isChar,
		isInt,
		isFloat,
		isDouble
	};
	int		i;

	for (i = 0; i < sizeof(funcs); i++) {
		if (funcs[i](val, Types, Display))
			break;
	}
	switch (i) {
		case SPECIAL:
			break;

		case CHAR:
			//convertFromVal(Types.c);
			break;

		case INT:
			//convertFromVal(Types.i);
			break;

		case FLOAT:
			//convertFromVal(Types.f);
			break;

		case DOUBLE:
			//convertFromVal(Types.d);
			break;

		default:

	}

	printResult( const_cast<const display&>(Display) );
}

#pragma region DetectType

static bool	isSpecial(const std::string_view val, types& Types, display& Display) {

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

// If input is a char - it is displayable.
static bool	isChar(const std::string_view val, types& Types, display& Display) {

	if ( val.length() == 1
		&& !std::isdigit( static_cast<unsigned char>(val[0]) ) )
	{
		Types.c = static_cast<unsigned char>(val[0]);
		Display.charStr = val;
		return (true);
	}
	return (false);
}

// std::string::npos is returned if nothing was found.
static bool	isInt(const std::string_view val, types& Types, display& Display) {

	std::string::size_type pos = 0;

	if (val[0] == '-' || val[0] == '+')
		pos = 1;
	if (val.find_first_not_of("1234567890", pos) != std::string::npos)
		return (false);

	try {
		Types.i = std::stoi(val);
		Display.intStr = val;
		return (true);
	}
	catch (std::out_of_range &e) {
		Display.intStr = outRange;
	}
	catch (std::invalid_argument &e) {}
	return (false);
}

static bool	isFloat(const std::string_view val, types& Types, display& Display) {

	try {
		Types.f = std::stof(val);
		Display.floatStr = val;
		return (true);
	}
	catch (std::out_of_range &e) {
		Display.floatStr = outRange;
	}
	catch (std::invalid_argument &e) {}
	return (false);
}

static bool	isDouble(const std::string_view val, types& Types, display& Display) {

	try {
		Types.d = std::stod(val);
		Display.doubleStr = val;
		return (true);
	}
	catch (std::out_of_range &e) {
		Display.doubleStr = outRange;
	}
	catch (std::invalid_argument &e) {}
	return (false);
}

static void	stoNum(const std::string_view val, types& Types, display& Display) {
	try {
		Types.d = std::from_chars(
			static_cast<const char*> (&val[0]),
			static_cast<const char*> (&val.back()),
			);
		Display.doubleStr = val;
		return (true);
	}
	catch (std::out_of_range &e) {
		Display.doubleStr = outRange;
	}
	catch (std::invalid_argument &e) {}
	return (false);
}
#pragma endregion

#pragma region Convert

convertFromVal() {}
	//if (ascii >= 32 && ascii <= 126) {
	//	Types.c = static_cast<char>(ascii);
	//	Display.charStr = static_cast<std::string>(&Types.c);
	//}
	//else if ((ascii >= 0 && ascii < 32) || ascii == 127) {
	//	Display.charStr =  nonDispl;
	//}

#pragma endregion

static void	printResult(const display& Display) {

	std::cout << "char: " << Display.charStr
		<< "\nint: " << Display.intStr
		<< "\nfloat: " << Display.floatStr
		<< "\ndouble: " << Display.doubleStr << std::endl;
}
