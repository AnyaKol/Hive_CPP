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
const int	PmergeMe::getSize(void) const {
	return (this->_vector.size());
}

const double	PmergeMe::getTimeVector(void) const {

	return (this->_timeVector.count());
}

const double	PmergeMe::getTimeDeque(void) const {
	return (this->_timeDeque.count());
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

void	PmergeMe::printSequence(void) const {
	vec_const_iterator	it = this->_vector.cbegin();
	vec_const_iterator	end = this->_vector.cend();

	for (; it != end; it++) {
		std::cout << *it;
		if (it + 1 != end)
			std::cout << " ";
	}
}

/* Each thread executes  _timeFunc  with arguments:
 * 	- function to sort container;
 * 	- reference to variable where to write time of execution.
 */
void	PmergeMe::sort(void) {
	if (this->getSize() < 2)
		return ;

	std::thread	vec(_timeFunc, _sortVector, this->_timeVector);
	std::thread	deq(_timeFunc, _sortDeque, this->_timeDeque);

	vec.join();
	deq.join();
}
#pragma endregion

#pragma region Private functions
void	PmergeMe::_timeFunc(void (*func)(void),
	std::chrono::duration<double>& time) {
	const time_point	start{std::chrono::high_resolution_clock::now()};
	func();
	const time_point	end{std::chrono::high_resolution_clock::now()};
	time = end - start;
}

// Start of reccursion
void	PmergeMe::_sortVector(void) {
	_sort(this->_vector, 1);
	if ( std::is_sorted( this->_vector.begin(), this->_vector.end() ) )
		std::cout << "Vector: Success!" << std::endl;
	else
		std::cout << "Vector: Fail!" << std::endl;
}

// Start of reccursion
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
 * 	4.	


 * 	1.	Create new container - for tail sequence; given container serves as main;
 * 	2.	Divide given sequence into pairs - bigger number to main;
 * 	3.	Create copy of main to later find pair by index;
 * 	4.	Pass new main (sequence of bigger numbers) to sort;
 * 	5.	Find in copy previous index of smallest number in sorted main and insert
 * 		it into main;
 * 	6.	Insert numbers from tail while tail isn't empty.
 * 
 * Insertion order:
 * 1. Get Jacobsthal number;
 * 2. Find size of the group;
 * 3. Start inserting into main numbers from tail from end to start of group;
 * 4. If tail isn't empty repeat with next Jacobsthal number.
*/
void	PmergeMe::_sort(std::vector<int>& container, const int elem_size) {
	if (container.size() < 2 * elem_size)
		return ;

	vec_iterator	it = container.begin() + elem_size - 1;
	vec_iterator	end = container.end();

// 1. Compare last element of pairs; elem_size - size of 1 element in pair
	for (; it < end; it += elem_size) {
		if (end - it <= elem_size)
				break ;

		vec_iterator	next = it + elem_size;

		if (*it > *next) {
			_swap_pairs(it - (elem_size - 1), elem_size);
		}
	}

// 2. Reccursion
	_sort(container, elem_size * 2);

// 3. Create empty container and split pairs
	std::vector<int>	tail{};

	it = container.begin() + (2 * elem_size);
	for (; it < end; it += 2 * elem_size) {
		if (end - it <= elem_size) {
			_push_elem();
			break ;
		}
		_push_elem(elem_size);
	}



//// 1. Create empty container tail
//	std::vector<int>	tail{};


//// 2. Divide into pairs
//	for (; it < end; it++) {
//		if (it + 1 == end || *it < *(it + 1)) {
//			tail.push_back(*it);
//			it = main.erase(it);
//			if (it == end)
//				break ;
//		} else {
//			tail.push_back(*(it + 1));
//			main.erase(it + 1);
//		}
//	}

//// 3. Copy main sequence
//	std::vector<int>	copy{main};

//// 4. Sort main sequence
//	_sort(main);// Recursion

//// 5. Insert pair of smallest number in main
//	it = copy.begin();
//	end = copy.end();

//	for (int i = 0; it + i < end; i++) {
//		if (*(it + i) == *main.begin()) {
//			main.insert(main.begin(), *(tail.begin() + i));
//			tail.erase(tail.begin() + i);
//			break ;
//		}
//		if (it + i == end - 1)
//			throw (NameException(ERR_NOPAIR, std::string_view{
//				std::to_string(*main.begin())
//			}));
//	}

//	int	i = 1;
//	int	jacob = 1;
//	int	groupSize;

//	while (tail.size() != 0) {
//		groupSize = -jacob;
//		jacob = _getJacobsthalNumber(i);
//		groupSize += jacob;
		
//	}
}

void	PmergeMe::_sort(std::deque<int>& container, const int elem_size) {
	if (container.size() < 2)
		return ;
}

// Find Jacobsthal number at index 'i'.
int	PmergeMe::_getJacobsthalNumber(int& i) {
	int	res = (std::pow(2, i + 2) - std::pow(-1, i)) / 3;
	i++;
	return (res);
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