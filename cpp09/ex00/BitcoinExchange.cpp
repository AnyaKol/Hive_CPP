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
// Using C++17 for string_view
#include <string_view>
#include <fstream>

// Constructors
BitcoinExchange::BitcoinExchange(const std::string& filename) {
	std::map<struct tm, float>	_data;

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

// Function to create data map.
#pragma region GetData
/* getline - from <string>*/
void	BitcoinExchange::_getData(std::string filename) {
	std::ifstream	input(filename);
	std::string		line;

	if (!input) {
		input.close();
		throw (NameException(ERR_NODATA, filename));
	}
	std::getline(input, line);
	while (std::getline(input, line)) {
		try {
			this->_getMapValue(line);
		} catch (NameException &e) {
			printError(e.what());
		} catch (Exception &e) {
			printError(e.what());
		}
	}
	input.close();
}

void	BitcoinExchange::_getMapValue(std::string line) {
	struct tm	date;
	float		num;
	std::size_t	pos{};

	_getDate(date, line, pos);
	_checkSymbol(line, pos, '|');
	_getValue(num, line, pos);

	const auto [it, success] { this->_data.insert(std::pair{ date, num }) };
	if (!success)
		throw (NameException(ERR_MAPADD, line));
}

// Extracts date from string in format 'YYYY-MM-DD' and checks if it is valid date.
void	BitcoinExchange::_getDate(struct tm& date, std::string line,
std::size_t& pos) {
	date.tm_year = std::stoi(line, &pos) - 1900;
	_checkSymbol(line, pos, '-');
	date.tm_mon = std::stoi(line, &pos) - 1;
	_checkSymbol(line, pos, '-');
	date.tm_mday = std::stoi(line, &pos);
	try {
		_checkDate(date);
	} catch (Exception &e) {
		throw (NameException(e.what(), line));
	}
}

void	BitcoinExchange::_getValue(float& num, std::string line,
std::size_t& pos) {
	try {
		num = std::stof(line, &pos);
	} catch (std::invalid_argument &e) {
		throw (NameException(ERR_NOVALUE, line));
	} catch (std::out_of_range &e) {
		throw (Exception(e.what()));
	}
	_checkSymbol(line, pos, '\0');
}

void	BitcoinExchange::_checkSymbol(std::string line, std::size_t& pos,
char c) {
	while (line[pos] == ' ')
		pos++;
	if (line[pos] != c)
		throw ( NameException(ERR_DATE_FORMAT, line) );
	pos++;
	while (line[pos] == ' ')
		pos++;
}

// mktime(&struct tm date) - converts 'date' to valid date.
void	BitcoinExchange::_checkDate(const struct tm& date) {
	struct tm	copy;

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
		throw (NameException(ERR_NODATA, filename));
	}
	std::getline(input, line);
	while (std::getline(input, line)) {
		try {
			this->_convertLine(line);
		} catch (NameException &e) {
			printError(e.what());
		}
	}
	std::cout << std::endl;
	input.close();
}

void	BitcoinExchange::_convertLine(const std::string& line) const {
	struct tm	date{};
	float		num{};
	float		result{};
	std::size_t	pos{};

	_getDate(date, line, pos);
	_getValue(num, line, pos);

	std::map<struct tm, float>::const_iterator	search = this->_data.find(date);
	if (search != this->_data.end()) {
		result = num * search->second;
	} else {
		result = 0;
	}

	std::cout << date.tm_year << "-" << date.tm_mon << "-" << date.tm_mday
		<< "=>" << num << " = " << result << std::endl;
}

#pragma endregion

#pragma region Exception

void	BitcoinExchange::printError(const std::string& msg) noexcept {
	std::cerr << "Error: " << msg << std::endl;
}

// Exception
BitcoinExchange::Exception::Exception(const std::string& message)
: _msg(message) {}

const char*	BitcoinExchange::Exception::what(void) const noexcept {
	return (this->_msg.c_str());
}

BitcoinExchange::NameException::NameException(const std::string& message,
const std::string& name) {
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
const std::string	BitcoinExchange::ERR_NOFILE = "No input file provided.";
const std::string	BitcoinExchange::ERR_NODATA = "Could not find";
const std::string	BitcoinExchange::ERR_DATE_FORMAT = "Wrong date format in line";
const std::string	BitcoinExchange::ERR_WRONG_DATE = "Wrong date in line";
const std::string	BitcoinExchange::ERR_NOVALUE = "No value for date";
const std::string	BitcoinExchange::ERR_MAPADD = "Failed to add date/value pair";

#pragma endregion