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
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange &other);
	~BitcoinExchange() {};

	struct	dateLess {
		bool	operator()(const std::tm& a, const std::tm& b) const;
	};

	typedef std::map<std::tm, float, dateLess>::iterator		iterator;
	typedef std::map<std::tm, float, dateLess>::const_iterator	const_iterator;
	typedef std::map<std::tm, float, dateLess>::value_type		value_type;

	void	convert(const std::string& date);

	static void	printError(std::string_view msg) noexcept;

	static const std::string	ERR_NOFILE;

	static const std::string	ERR_NODATA;
	static const std::string	ERR_DATE_FORMAT;
	static const std::string	ERR_WRONG_DATE;
	static const std::string	ERR_NOVALUE;
	static const std::string	ERR_NEGVALUE;
	static const std::string	ERR_OUTRANGE;
	static const std::string	ERR_MAPADD;
	static const std::string	ERR_DATE_OUTRANGE;

	class	Exception;
	class	NameException;

private:

	BitcoinExchange(void) = delete;

	void	_getData(const std::string& filename);
	void	_getMapValue(std::string_view line);
	void	_convertLine(std::string_view line) const;

	static void	_getDate(std::tm& date, std::string_view line, std::size_t& pos);
	static void	_getValue(float& num, std::string_view line, std::size_t& pos);
	static void	_checkSymbol(std::string_view line, std::size_t& pos, char c);
	static void	_checkDate(const std::tm& date);
	static void	_printDate(const std::tm& date);

	std::map<std::tm, float, dateLess>	_data;
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
	NameException(const std::string& message, std::string_view name);
	const char*	what(void) const noexcept override;
private:
	NameException(void) = delete;
	std::string	_msg;
};
