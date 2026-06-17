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
#include <string>
#include <fstream>

// Constructors
BitcoinExchange::BitcoinExchange(const std::string& filename) {

	std::map<struct tm, float>	_data;

	this->_get_data(filename);
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

// Helpers
/* getline - from <string>*/
void	BitcoinExchange::_get_data(std::string filename) {

	std::ifstream	input(filename);
	std::string		line;

	if (!input) {
		input.close();
		throw (NameException(ERR_NODATA, filename));
	}
	std::getline(input, line);
	while (std::getline(input, line)) {
		try {
			this->_get_date(line);
		} catch (BitcoinExchange::NameException &e) {
			printError(e.what());
		}
	}
	input.close();
}

void	BitcoinExchange::_get_date(std::string line) {

	struct tm	date;
	std::size_t	pos{};

	date.tm_year = std::stoi(line, &pos) - 1900;
	if (line[pos] != '-')
		throw (NameException(ERR_DATE_FORMAT, line));
	date.tm_mon = std::stoi(line, &pos) - 1;
	if (line[pos] != '-')
		throw (NameException(ERR_DATE_FORMAT, line));
	date.tm_mday = std::stoi(line, &pos);
	while (line[pos] == ' ')
		pos++;
	if (line[pos] != '|')
		throw (NameException(ERR_DATE_FORMAT, line));
}

// Main function
void	BitcoinExchange::convert(const std::string& filename) {

	std::ifstream	input(filename);
	std::string		line;

	if (!input) {
		input.close();
		throw (NameException(ERR_NODATA, filename));
	}
	while (std::getline(input, line)) {
		std::cout << line << "\n";
	}
	std::cout << std::endl;
	input.close();
}

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
const std::string	BitcoinExchange::ERR_NODATA = "Could not find '";
const std::string	BitcoinExchange::ERR_DATE_FORMAT = "Wrong date format in line '";