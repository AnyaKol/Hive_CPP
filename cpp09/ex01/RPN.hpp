/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:04:56 by akolupae          #+#    #+#             */
/*   Updated: 2026/07/05 10:04:58 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <string_view>

class RPN {

public:

	RPN() {};
	RPN(const RPN& other);
	RPN&	operator=(const RPN& other);
	~RPN() {};

	void	add(std::string_view str);
	int		getResult(void) const;

	static void	printError(std::string_view msg) noexcept;

	static const std::string	ERR_WNUM;
	static const std::string	ERR_WINPUT;

	class Exception;
	class NameException;

private:

	void	_addOne(unsigned char value);
	void	_applySign(unsigned char value);

	std::stack<int>	_stack;
};

class RPN::Exception : public std::exception {
public:
	Exception(const std::string& message);
	const char*	what(void) const noexcept override;
private:
	Exception(void) = delete;
	const std::string&	_msg;
};

class RPN::NameException : public std::exception {
public:
	NameException(const std::string& message, std::string_view name);
	const char*	what(void) const noexcept override;
private:
	NameException(void) = delete;
	std::string	_msg;
};
