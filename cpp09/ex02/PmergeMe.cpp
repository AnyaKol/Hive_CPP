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
#include <stdexcept>
#include <cmath>
#include <algorithm>

#pragma region Class init and getters
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

double	PmergeMe::getTimeVector(void) const {
	return (this->_timeVector.count());
}

double	PmergeMe::getTimeDeque(void) const {
	return (this->_timeDeque.count());
}

const std::vector<int>&	PmergeMe::getSequence(void) const {
	return (this->_vector);
}
#pragma endregion

#pragma region Public functions
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

void	PmergeMe::sort(void) {
	if (this->getSize() < 2)
		return ;

	_timeFunc( &PmergeMe::_sortVector, this->_timeVector );
	_timeFunc( &PmergeMe::_sortDeque, this->_timeDeque );
}
#pragma endregion

#pragma region Private functions
/* Class std::chrono::steady_clock represents a monotonic clock most suitable
 * for measuring intervals.
 * For duration using std::ratio<1, 1000> - std::milli (milliseconds).
 */
void	PmergeMe::_timeFunc(void (PmergeMe::*func)(void),
	std::chrono::duration<double, std::milli>& time) {
	const time_point	start{std::chrono::steady_clock::now()};
	(this->*func)();
	const time_point	end{std::chrono::steady_clock::now()};
	time = end - start;
}

void	PmergeMe::_sortVector(void) {
	_sort(this->_vector, 1);
	if ( std::is_sorted( this->_vector.begin(), this->_vector.end() ) )
		std::cout << "Vector: Success!" << std::endl;
	else
		std::cout << "Vector: Fail!" << std::endl;
}

void	PmergeMe::_sortDeque(void) {
	_sort(this->_deque, 1);
	if ( std::is_sorted( this->_deque.begin(), this->_deque.end() ) )
		std::cout << "Deque: Success!" << std::endl;
	else
		std::cout << "Deque: Fail!" << std::endl;
}

/* Sorting:
 * 	1.	Perform comparisons and swap (if necessary) members of pairs; size of 1
 * 		member of pair is 2^ 'level of reccursion' (1, 2, 4...);
 * 	2.	Pass sequence to next level of reccursion and pass double of element size;
 * 	3.	Create empty tail container and push there smaller element of each pair
 * 		except the first;
 * 	4.	Push elements from tail back to main using Jacobsthal numbers and
 * 		binary search.
 * 
 * Insertion order:
 * 	1.	Get Jacobsthal number;
 * 	2.	Find size of the group;
 * 	3.	Start inserting into main numbers from tail from end to start of group;
 * 	4.	If tail isn't empty repeat with next Jacobsthal number.
*/
void	PmergeMe::_sort(std::vector<int>& container, const int elemSize) {
	if (container.size() < static_cast<long unsigned int>(2 * elemSize))
		return ;

	vec_iterator	it = container.begin();
	vec_iterator	end = container.end();

// 1. Compare last element of pairs; elemSize - size of 1 element in pair
	for (; end - it >= 2 * elemSize; it += 2 * elemSize) {
		vec_iterator	next = it + elemSize;

		if ( *(it + (elemSize - 1)) > *(next + (elemSize - 1)) ) {
			_swapPairs(it, elemSize);
		}
	}

// 2. Reccursion
	_sort(container, elemSize * 2);

// 3. Create empty container and split pairs
	std::vector<int>	tail{};

	it = container.begin() + (2 * elemSize);
	for (; end - it >= elemSize; it += elemSize) {
		it = _pushElem(container, it, tail, elemSize);
		end = container.end();
		if (end - it < elemSize)
			break;
	}

// 4. Insert elements from tail back to main
	_insertTail(container, tail, elemSize);
}

void	PmergeMe::_sort(std::deque<int>& container, const int elemSize) {
	if (container.size() < static_cast<long unsigned int>(2 * elemSize))
		return ;

	deq_iterator	it = container.begin();
	deq_iterator	end = container.end();

	for (; end - it >= 2 * elemSize; it += 2 * elemSize) {
		deq_iterator	next = it + elemSize;

		if ( *(it + (elemSize - 1)) > *(next + (elemSize - 1)) ) {
			_swapPairs(it, elemSize);
		}
	}
	_sort(container, elemSize * 2);

	std::deque<int>	tail{};

	it = container.begin() + (2 * elemSize);
	for (; end - it >= elemSize; it += elemSize) {
		it = _pushElem(container, it, tail, elemSize);
		end = container.end();
		if (end - it < elemSize)
			break;
	}
	_insertTail(container, tail, elemSize);
}

// Find Jacobsthal number at index 'i'.
int	PmergeMe::_getJacobsthalNumber(int i) {
	return ( (std::pow(2, i + 2) - std::pow(-1, i)) / 3 );
}

int	PmergeMe::_getBinarySearchRange(int jacobIndex) {
	return ( std::pow(2, jacobIndex + 1) - 1 );
}
#pragma endregion

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
const std::string	PmergeMe::ERR_NOPAIR = "Couldn't find pair for";

#pragma endregion