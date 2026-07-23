/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:04:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/07/05 10:04:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <cctype>
#include <limits>

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return (*this);
}

void	RPN::add(std::string_view str) {
	for (std::size_t i = 0; i < str.length(); i++) {
		if (str[i] != ' ')
			this->_addOne( static_cast<unsigned char>(str[i]) );
	}
}

void	RPN::_addOne(unsigned char value) {
	if ( std::isdigit(value) != 0 )
		this->_stack.push( static_cast<int>(value - '0') );
	else if (value == '+' || value == '-' || value == '*' || value == '/')
		this->_applySign(value);
	else
		throw (NameException(ERR_WINPUT,
			std::string_view{ std::string{ static_cast<char>(value) } }
		));
}

// If there are less than 2 numbers in the stack, can't apply the operator.
void	RPN::_applySign(unsigned char value) {
	if (this->_stack.size() < 2)
		throw (Exception(ERR_WNUM));

	int	a {this->_stack.top()};
	this->_stack.pop();
	int	b {this->_stack.top()};
	this->_stack.pop();

	_checkOverflow(static_cast<float>(a), static_cast<float>(b), value);
	if (value == '+')
		this->_stack.push(a + b);
	else if (value == '-')
		this->_stack.push(b - a);
	else if (value == '*')
		this->_stack.push(a * b);
	else
		this->_stack.push(b / a);
}

void	RPN::_checkOverflow(float a, float b, unsigned char value) {
	float	res;

	if (value == '+')
		res = a + b;
	else if (value == '-')
		res = b - a;
	else if (value == '*')
		res = a * b;
	else {
		if (a == 0)
			throw (Exception(ERR_ZERO));
		res = b / a;
	}

	if (res > static_cast<float>( std::numeric_limits<int>::max() )
		|| res < static_cast<float>( std::numeric_limits<int>::min() ))
		throw (Exception(ERR_OVERFLOW));
}

int	RPN::getResult(void) const {
	if (this->_stack.size() != 1)
		throw (Exception(ERR_WNUM));

	return (this->_stack.top());
}

#pragma region Exception

void	RPN::printError(std::string_view msg) noexcept {
	std::cerr << "Error: " << msg << std::endl;
}

RPN::Exception::Exception(const std::string& message)
: _msg(message) {}

const char*	RPN::Exception::what(void) const noexcept {
	return (this->_msg.c_str());
}

RPN::NameException::NameException(const std::string& message,
std::string_view name) {
	this->_msg = message;
	this->_msg.append(" '");
	this->_msg.append(name);
	this->_msg.append("'.");
}

const char*	RPN::NameException::what(void) const noexcept {
	return (this->_msg.c_str());
}

// Exception
const std::string	RPN::ERR_WNUM = "Wrong number of values or operators.";
const std::string	RPN::ERR_ZERO = "Division by 0.";
const std::string	RPN::ERR_OVERFLOW = "Int overflow.";

// NameException
const std::string	RPN::ERR_WINPUT = "Wrong input";


#pragma endregion
