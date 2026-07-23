/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:30:46 by akolupae          #+#    #+#             */
/*   Updated: 2026/06/11 19:30:50 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <limits>
// Using C++17 for string_view.
#include <string_view>
#include <fstream>

// Constructors
BitcoinExchange::BitcoinExchange(const std::string& filename) {
	this->_getData(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_data = other._data;
	}
	return (*this);
}

bool	BitcoinExchange::dateLess::operator()(const std::tm& a, const std::tm& b) const {
	return (a.tm_year < b.tm_year
		|| (a.tm_year == b.tm_year && a.tm_mon < b.tm_mon )
		|| (a.tm_year == b.tm_year && a.tm_mon == b.tm_mon && a.tm_mday < b.tm_mday));
}

// Function to create data map.
#pragma region GetData
// getline - from <string>
/* Using const string& here, because string_view is not guaranteed to be
 * null-terminated, which is needed for ifstream.
 */
void	BitcoinExchange::_getData(const std::string& filename) {
	std::ifstream	input(filename);
	std::string		line;

	if (!input) {
		input.close();
		throw (NameException(ERR_NODATA, std::string_view{filename}));
	}
	std::getline(input, line);
	while (std::getline(input, line)) {
		try {
			this->_getMapValue(std::string_view{line});
		} catch (NameException &e) {
			printError(std::string_view{e.what()});
		} catch (Exception &e) {
			printError(std::string_view{e.what()});
		}
	}
	input.close();
}

void	BitcoinExchange::_getMapValue(std::string_view line) {
	value_type	result{};
	std::size_t	pos{};

	_getDate(const_cast<std::tm&>(result.first), line, pos);
	_checkSymbol(line, pos, ',');
	_getValue(result.second, line, pos);

	const std::pair<const_iterator, bool> pair = this->_data.insert(result);
	if (!pair.second)
		throw (NameException(ERR_MAPADD, line));
}

// Extracts date from string in format 'YYYY-MM-DD' and checks if it is valid date.
void	BitcoinExchange::_getDate(std::tm& date, std::string_view line,
std::size_t& pos) {
	std::size_t	processed{};

	date.tm_year = std::stoi(&line[pos], &processed) - 1900;
	pos += processed;
	_checkSymbol(line, pos, '-');
	date.tm_mon = std::stoi(&line[pos], &processed) - 1;
	pos += processed;
	_checkSymbol(line, pos, '-');
	date.tm_mday = std::stoi(&line[pos], &processed);
	pos += processed;
	try {
		_checkDate(date);
	} catch (Exception &e) {
		throw (NameException(e.what(), line));
	}
}

/* Function checks that:
 * - value is a number,
 * - it is in range,
 * - there is nothing after number in the string.
 *
 * 	Here acceptable value range is [0, INT_MAX]; upper bound could be increased
 * to FLOAT_MAX / 1000.
 */
void	BitcoinExchange::_getValue(float& num, std::string_view line,
std::size_t& pos) {
	std::size_t	processed{};

	try {
		num = std::stof(&line[pos], &processed);
		pos += processed;
	} catch (std::invalid_argument &e) {
		throw (NameException(ERR_NOVALUE, line));
	} catch (std::out_of_range &e) {
		throw (Exception(e.what()));
	}

	if (num < 0)
		throw ( NameException(ERR_NEGVALUE, line) );
	if (num >= static_cast<float>(std::numeric_limits<int>::max()))
		throw ( NameException(ERR_OUTRANGE, line) );

	if (pos != line.length())
		throw ( NameException(ERR_DATE_FORMAT, line) );
}

void	BitcoinExchange::_checkSymbol(std::string_view line, std::size_t& pos,
char c) {
	while (line[pos] == ' ')
		pos++;
	if (line[pos] != c)
		throw ( NameException(ERR_DATE_FORMAT, line) );
	pos++;
	while (line[pos] == ' ')
		pos++;
}

// mktime(std::tm date) - converts 'date' to valid date.
void	BitcoinExchange::_checkDate(const std::tm& date) {
	std::tm	copy;

	copy = date;
	mktime(&copy);
	if (date.tm_year != copy.tm_year
		|| date.tm_mon != copy.tm_mon
		|| date.tm_mday != copy.tm_mday)
		throw (Exception(ERR_WRONG_DATE));
}

#pragma endregion

// Main function
#pragma region Convert

void	BitcoinExchange::convert(const std::string& filename) {
	std::ifstream	input(filename);
	std::string		line;

	if (!input) {
		input.close();
		throw (NameException(ERR_NODATA, std::string_view{filename}));
	}
	std::getline(input, line);
	std::cout << line << std::endl;
	while (std::getline(input, line)) {
		try {
			this->_convertLine(std::string_view{line});
		} catch (NameException &e) {
			printError(std::string_view{e.what()});
		}
	}
	std::cout << std::endl;
	input.close();
}

// Here acceptable value range is [0, 1000]
void	BitcoinExchange::_convertLine(std::string_view line) const {
	value_type	value{};
	float		result{};
	std::size_t	pos{};

	_getDate(const_cast<std::tm&>(value.first), line, pos);
	_checkSymbol(line, pos, '|');
	_getValue(value.second, line, pos);
	if (value.second > 1000)
		throw ( NameException(ERR_OUTRANGE, line) );

	const_iterator	search = this->_data.upper_bound(value.first);
	if (search == this->_data.begin())
		throw ( NameException(ERR_DATE_OUTRANGE, line) );
	search--;
	result = value.second * search->second;

	_printDate(value.first);
	std::cout << " => " << value.second << " = " << result
		<< std::endl;
}

void	BitcoinExchange::_printDate(const std::tm& date) {
	std::cout << date.tm_year + 1900 << "-";

	if (date.tm_mon < 9)
		std::cout << "0";
	std::cout << date.tm_mon + 1 << "-";

	if (date.tm_mday < 10)
		std::cout << "0";
	std::cout << date.tm_mday;
}

#pragma endregion

#pragma region Exception

void	BitcoinExchange::printError(std::string_view msg) noexcept {
	std::cerr << "Error: " << msg << std::endl;
}

// Exception
/* Not using string_view in exceptions because they need to construct a c-string
 * from msg.
 */
BitcoinExchange::Exception::Exception(const std::string& message)
: _msg(message) {}

const char*	BitcoinExchange::Exception::what(void) const noexcept {
	return (this->_msg.c_str());
}

BitcoinExchange::NameException::NameException(const std::string& message,
std::string_view name) {
	this->_msg = message;
	this->_msg.append(" '");
	this->_msg.append(name);
	this->_msg.append("'.");
}

const char*	BitcoinExchange::NameException::what(void) const noexcept {
	return (this->_msg.c_str());
}

/* Assigning value to string in .cpp file, otherwise every file to include .hpp
 * file would havea copy of string.
 */
// Exception
const std::string	BitcoinExchange::ERR_NOFILE = "No input file provided.";

// NameException, no '.' at the end
const std::string	BitcoinExchange::ERR_NODATA = "Could not find";
const std::string	BitcoinExchange::ERR_DATE_FORMAT = "Wrong date format";
const std::string	BitcoinExchange::ERR_WRONG_DATE = "Wrong date";
const std::string	BitcoinExchange::ERR_NOVALUE = "No value for date";
const std::string	BitcoinExchange::ERR_NEGVALUE = "Value is negative number";
const std::string	BitcoinExchange::ERR_OUTRANGE = "Value number is too large";
const std::string	BitcoinExchange::ERR_MAPADD = "Failed to add date/value pair";
const std::string	BitcoinExchange::ERR_DATE_OUTRANGE = "Date is before start of database";

#pragma endregion