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

	static void	BitcoinExchange::printError(const std::string& msg) noexcept;

	static const std::string	ERR_NOFILE;
	static const std::string	ERR_NODATA;
	static const std::string	ERR_DATE_FORMAT;

	class	Exception;
	class	NameException;

private:

	BitcoinExchange(void) = delete;

	void	_get_data(std::string filename);
	void	_get_date(std::string line);

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
