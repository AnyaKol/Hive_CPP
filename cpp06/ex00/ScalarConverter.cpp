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
#include <climits>
// Using C++17 for string_view and from_chars
#include <string_view>
#include <charconv>

// Copy assignment operator overload
ScalarConverter&	ScalarConverter::operator= (const ScalarConverter&) {

	return (*this);
}

// ScalarConverter function
#pragma region Declarations

enum typeName{
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

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

static bool	isSpecial(const std::string_view str, types& Types,
	display& Display);
static bool	isChar(const std::string_view str, types& Types, display& Display);
static bool	isInt(const std::string_view str, types& Types, display& Display);
static bool	isFloat(const std::string_view str, types& Types, display& Display);
static bool	isDouble(const std::string_view str, types& Types,
	display& Display);
static void	addPrecision(std::string& str);
static void	printResult(const display& Display);

template <typename T> constexpr bool	strToNum(const std::string_view str,
	T& val, std::string& displayStr) {

	std::from_chars_result	res;

	res = std::from_chars(str.data(), str.data() + str.size(), val);
	if (res.ec == std::errc::result_out_of_range) {
		displayStr = outRange;
		return (false);
	}
	if (res.ptr != str.data() + str.size())
		return (false);

	displayStr = std::to_string(val);
	return (true);
}

// T can be char, int, float or double
template <typename T> constexpr void	convertFromVal(const T val, types& Types,
	display& Display) {

	double	bigVal(val);

	// Convert to char if val is not char
	if ( !std::is_same<T, char>::value ) {

		if ( bigVal >= 32 && bigVal <= 126 ) {
			Types.c = static_cast<char>(val);
			Display.charStr = Types.c;
		}
		else if ( (bigVal >= 0 && bigVal < 32) || bigVal == 127 ) {
			Display.charStr =  nonDispl;
		}
	}

	// Convert to int if val is not int
	if ( !std::is_same<T, int>::value ) {
		if ( bigVal >= static_cast<double>(INT_MIN)
			&& bigVal <= static_cast<double>(INT_MAX) ) {
			Types.i = static_cast<int>(val);
			Display.intStr = std::to_string(Types.i);
		}
	}

	// Convert to float if val is not float
	if ( !std::is_same<T, float>::value ) {
		if ( bigVal >= static_cast<double>(std::numeric_limits<float>::lowest())
			&& bigVal <= static_cast<double>(std::numeric_limits<float>::max()) ) {
			Types.f = static_cast<float>(val);
			Display.floatStr = std::to_string(Types.f);
			addPrecision(Display.floatStr);
			Display.floatStr += "f";
		}
	}

	// Convert to double if val is not double
	// Don't check limits here - double is the biggest type val can be.
	if ( !std::is_same<T, double>::value ) {
		Types.d = static_cast<double>(val);
		Display.doubleStr = std::to_string(Types.d);
		addPrecision(Display.floatStr);
	}
	
}

#pragma endregion

void	ScalarConverter::convert(const std::string_view str) {

	types	Types;
	display	Display;
	bool (* funcs[])(const std::string_view str, types& Types, display& Display)
		= {
		isSpecial,
		isChar,
		isInt,
		isFloat,
		isDouble
	};
	std::size_t	i;
	std::size_t	arrSize { std::size(funcs) };


	for ( i = 0; i < arrSize; i++ ) {
		if (funcs[i](str, Types, Display))
			break;
	}
	switch (i) {
		case SPECIAL: break;

		case CHAR:
			std::cout << "Type is char: " << Types.c << std::endl;
			convertFromVal(Types.c, Types, Display);
			break;

		case INT:
			std::cout << "Type is int: " << Types.i << std::endl;
			convertFromVal(Types.i, Types, Display);
			break;

		case FLOAT:
			std::cout << "Type is float: " << Types.f << std::endl;
			convertFromVal(Types.f, Types, Display);
			break;

		case DOUBLE:
			std::cout << "Type is double: " << Types.d << std::endl;
			convertFromVal(Types.d, Types, Display);
			break;
	}

	printResult( const_cast<const display&>(Display) );
}

#pragma region DetectType

static bool	isSpecial(const std::string_view str, types& Types, display& Display) {

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
		if (specials[i] == str)
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
static bool	isChar(const std::string_view str, types& Types, display& Display) {

	if ( str.length() == 1
		&& !std::isdigit( static_cast<unsigned char>(*str.data()) ) )
	{
		Types.c = static_cast<char>(*str.data());
		Display.charStr = str;
		return (true);
	}
	return (false);
}

// std::string::npos is returned if nothing was found.
static bool	isInt(const std::string_view str, types& Types, display& Display) {

	std::string::size_type pos = 0;

	if (str[0] == '-')
		pos = 1;
	if (str.find_first_not_of("1234567890", pos) != std::string::npos)
		return (false);

	return (strToNum(str, Types.i, Display.intStr));
}

static bool	isFloat(const std::string_view str, types& Types, display& Display) {

	if (str.back() != 'f')
		return (false);

	std::string	numStr(str);
	numStr.pop_back();

	if ( strToNum(numStr, Types.f, Display.floatStr) ) {
		addPrecision(Display.floatStr);
		Display.floatStr += "f";
		return (true);
	}

	return (false);
}

static bool	isDouble(const std::string_view str, types& Types, display& Display) {

	if ( strToNum(str, Types.d, Display.doubleStr) ) {
		addPrecision(Display.doubleStr);
		return (true);
	}
	return (false);
}

static void	addPrecision(std::string& str) {

	for (char c : str) {
		if (c == '.')
			return;
	}
	str += ".0";
}

#pragma endregion

static void	printResult(const display& Display) {

	std::cout << "char: " << Display.charStr
		<< "\nint: " << Display.intStr
		<< "\nfloat: " << Display.floatStr
		<< "\ndouble: " << Display.doubleStr << std::endl;
}
