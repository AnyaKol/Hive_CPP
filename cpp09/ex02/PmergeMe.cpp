/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:10:12 by akolupae          #+#    #+#             */
/*   Updated: 2026/07/06 13:10:14 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <thread>

// Initialise everithing to default values.
PmergeMe::PmergeMe(void) {
	this->_vector = {};
	this->_deque = {};
	this->_timeVector = {};
	this->_timeDeque = {};
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vector = other._vector;
		this->_deque = other._deque;
		this->_timeVector = other._timeVector;
		this->_timeDeque = other._timeDeque;
	}
	return (*this);
}

// Getters
int	PmergeMe::getSize(void) const {
	return (this->_vector.size());
}

const std::chrono::duration<double>&	PmergeMe::getTimeVector(void) const {
	return (this->_timeVector);
}

const std::chrono::duration<double>&	PmergeMe::getTimeDeque(void) const {
	return (this->_timeDeque);
}

// Functions
void	PmergeMe::add(std::string_view str) {
	std::size_t	processed{};
	int			num;

	try {
		num = std::stoi(&str[0], &processed);
	} catch (std::invalid_argument &e) {
		throw (NameException(e.what(), str));
	} catch (std::out_of_range &e) {
		throw (NameException(e.what(), str));
	}
	if (processed < str.length())
		throw (NameException(ERR_WINPUT, str));

	this->_vector.push_back(num);
	this->_deque.push_back(num);
}

void	PmergeMe::printSequence(void) const {
	std::vector<int>::const_iterator	it = this->_vector.cbegin();
	std::vector<int>::const_iterator	end = this->_vector.cend();

	for (; it != end; it++) {
		std::cout << *it;
		if (it + 1 != end)
			std::cout << " ";
	}
}

void	PmergeMe::sort(void) {
	if (this->getSize() < 2)
		return ;

	std::thread	vec(_timeFunc, _sortVector, this->_timeVector);
	std::thread	deq(_timeFunc, _sortDeque, this->_timeDeque);

	vec.join();
	deq.join();
}

void	PmergeMe::_timeFunc(void (*func)(void),
	std::chrono::duration<double>& time) {
	const std::chrono::time_point<std::chrono::high_resolution_clock>	start
		{std::chrono::high_resolution_clock::now()};
	func();
	const std::chrono::time_point<std::chrono::high_resolution_clock>	end
		{std::chrono::high_resolution_clock::now()};
	time = end - start;
}

void	PmergeMe::_sortVector(void) {

}

void	PmergeMe::_sortDeque(void) {

}



#pragma region Exception

void	PmergeMe::printError(std::string_view msg) noexcept {
	std::cerr << "Error: " << msg << std::endl;
}

// Exception
/* Not using string_view in exceptions because they need to construct a c-string
 * from msg.
 */
PmergeMe::Exception::Exception(const std::string& message)
: _msg(message) {}

const char*	PmergeMe::Exception::what(void) const noexcept {
	return (this->_msg.c_str());
}

PmergeMe::NameException::NameException(const std::string& message,
std::string_view name) {
	this->_msg = message;
	this->_msg.append(" '");
	this->_msg.append(name);
	this->_msg.append("'.");
}

const char*	PmergeMe::NameException::what(void) const noexcept {
	return (this->_msg.c_str());
}

/* Assigning value to string in .cpp file, otherwise every file to include .hpp
 * file would havea copy of string.
 */
// NameException, no '.' at the end
const std::string	PmergeMe::ERR_WINPUT = "Wrong input";

#pragma endregion