/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:10:23 by akolupae          #+#    #+#             */
/*   Updated: 2026/07/06 13:10:24 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <deque>
#include <chrono>
#include <iostream>

class PmergeMe {

public:

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe() {};

	typedef std::vector<int>::iterator			vec_iterator;
	typedef std::vector<int>::const_iterator	vec_const_iterator;
	typedef std::deque<int>::iterator			deq_iterator;

	typedef std::chrono::time_point<std::chrono::steady_clock>	time_point;

	int						getSize(void) const;
	double					getTimeVector(void) const;
	double					getTimeDeque(void) const;
	const std::vector<int>&	getSequence(void) const;

	void	add(std::string_view str);
	void	sort(void);

	template <typename T, typename U = typename T::const_iterator>
	static void	printSequence(T& container) {
		U	it = container.cbegin();
		U	end = container.cend();

		for (; it != end; it++) {
			std::cout << *it;
			if (it + 1 != end)
				std::cout << " ";
		}
	};

	static void	printError(std::string_view msg) noexcept;

	static const std::string	ERR_WINPUT;
	static const std::string	ERR_NOPAIR;

	class	Exception;
	class	NameException;

private:

	static int	_getJacobsthalNumber(int i);
	static int	_getBinarySearchRange(int jacobIndex);

	void	_timeFunc(void (PmergeMe::*func)(void), std::chrono::duration<double, std::milli>& time);
	void	_sortVector(void);
	void	_sortDeque(void);
	void	_sort(std::vector<int>& container, const int elemSize);
	void	_sort(std::deque<int>& container, const int elemSize);

	/* Swaps 'elemSize' elements starting from 'it' and moves 'it' to the last
	 * element of swapped sequence.
	 */
	template <typename U>
	void	_swapPairs(U it, const int elemSize) {
		U	end = it + elemSize;
		int	temp;

		for (; it < end; it++) {
			U	next = it + elemSize;

			temp = *it;
			*it = *next;
			*next = temp;
		}
	};

	/* _pushElem moves iterator 'it' to the first number after pushed element.
	 */
	template <typename T, typename U = typename T::iterator>
	U	_pushElem(T& container, U it, T& tail, const int elemSize) {
		tail.insert(tail.end(), it, it + elemSize);
		it = container.erase(it, it + elemSize);
		return (it);
	};

	/* main_it points to last number of element at position 'middle';
	 * 'insert_pos' is a position after which to insert; it can have values in range [0, high];
	 * inserting after 'insert_pos' = 0 means inserting at the beginning of range;
	 * 'main_insert_it' is calculated from 'insert_pos'; values in range [main.begin(), main.begin() + main.size()];
	 */
	template <typename T, typename U = typename T::iterator>
	U	_binarySearchInsert(T& main, T& tail, U tail_end, const int elemSize,
		const int jacobIndex) {
	// 1. Find position in main after which to insert element from tail.
		int	insert_pos = 0;
		int low = 1;
		int high = std::min(static_cast<int>(main.size() / elemSize),
			_getBinarySearchRange(jacobIndex));
		int	middle;

		while (high >= low) {
			middle = (high + low) / 2;
			U main_it = main.begin() + (middle * elemSize - 1);

			if (*(tail_end - 1) >= *main_it) {
				insert_pos = middle;
				if (*(tail_end - 1) == *main_it)
					break;
				low = middle + 1;
			}
			else
				high = middle - 1;
		}

	// 2. Insert current element in tail to main and erase it from tail.
		U main_insert = main.begin() + (insert_pos * elemSize);

		for (int i = 0; i < elemSize; i++) {
			main_insert = main.insert(main_insert, *(tail_end - 1));
			tail_end = tail.erase(tail_end - 1);
			if ( tail.empty() )
				break;
		}
		return (tail_end);
	};

	template <typename T, typename U = typename T::iterator>
	void	_insertTail(T& main, T& tail, const int elemSize) {
		int	jacobIndex = 1;
		int	jacobNum = 1;
		int	groupSize;
		U	it;

		while ( !tail.empty() ) {
			groupSize = -jacobNum;
			jacobNum = _getJacobsthalNumber(jacobIndex);
			groupSize += jacobNum;
			it = tail.begin() + std::min(static_cast<int>(tail.size()), groupSize * elemSize);

			for (int i = 0; i < groupSize; i++) {
				it = _binarySearchInsert(main, tail, it, elemSize, jacobIndex);
				if ( tail.empty() )
					break;
			}
			jacobIndex++;
		}
	};

	std::vector<int>	_vector;
	std::deque<int>		_deque;
	std::chrono::duration<double, std::milli>	_timeVector;
	std::chrono::duration<double, std::milli>	_timeDeque;
};

class	PmergeMe::Exception : public std::exception {
public:
	Exception(const std::string& message);
	const char*	what(void) const noexcept override;
private:
	Exception(void) = delete;
	const std::string&	_msg;
};

class	PmergeMe::NameException : public std::exception {
public:
	NameException(const std::string& message, std::string_view name);
	const char*	what(void) const noexcept override;
private:
	NameException(void) = delete;
	std::string	_msg;
};

