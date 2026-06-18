/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:31:00 by akolupae          #+#    #+#             */
/*   Updated: 2026/06/11 19:31:02 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <ctime>

class	BitcoinExchange {

public:

	BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange&	operator=(const BitcoinExchange &other);
	~BitcoinExchange() {};

	void	convert(const std::string& date);

	static void	printError(const std::string& msg) noexcept;

	static const std::string	ERR_NOFILE;
	static const std::string	ERR_NODATA;
	static const std::string	ERR_DATE_FORMAT;
	static const std::string	ERR_WRONG_DATE;
	static const std::string	ERR_NOVALUE;
	static const std::string	ERR_MAPADD;

	class	Exception;
	class	NameException;

private:

	BitcoinExchange(void) = delete;

	void	_getData(std::string filename);
	void	_getMapValue(std::string line);
	void	_convertLine(const std::string& line) const;

	static void	_getDate(struct tm& date, std::string line, std::size_t& pos);
	static void	_getValue(float& num, std::string line, std::size_t& pos);
	static void	_checkSymbol(std::string line, std::size_t& pos, char c);
	static void	_checkDate(const struct tm& date);

	std::map<struct tm, float>	_data;
};

class	BitcoinExchange::Exception : public std::exception {
public:
	Exception(const std::string& message);
	const char*	what(void) const noexcept override;
private:
	Exception(void) = delete;
	const std::string&	_msg;
};

class	BitcoinExchange::NameException : public std::exception {
public:
	NameException(const std::string& message, const std::string& name);
	const char*	what(void) const noexcept override;
private:
	NameException(void) = delete;
	std::string	_msg;
};
