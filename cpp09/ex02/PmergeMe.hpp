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

class PmergeMe {

public:

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe() {};

	typedef std::vector<int>::iterator			vec_iterator;
	typedef std::vector<int>::const_iterator	vec_const_iterator;
	typedef std::deque<int>::iterator			deq_iterator;

	typedef std::chrono::time_point<std::chrono::high_resolution_clock>	time_point;

	const int		getSize(void) const;
	const double	getTimeVector(void) const;
	const double	getTimeDeque(void) const;

	void	add(std::string_view str);
	void	printSequence(void) const;
	void	sort(void);

	static void	printError(std::string_view msg) noexcept;

	static const std::string	ERR_WINPUT;
	static const std::string	ERR_NOPAIR;

	class	Exception;
	class	NameException;

private:

	static void	_timeFunc(void (*func)(void), std::chrono::duration<double>& time);
	static int	_getJacobsthalNumber(int& i);

	void	_sortVector(void);
	void	_sortDeque(void);
	void	_sort(std::vector<int>& container, const int elemSize);
	void	_sort(std::deque<int>& container, const int elemSize);

	/* Swaps 'elemSize' elements starting from 'it' and moves 'it' to the last
	 * element of swapped sequence.
	 */
	template <typename T, typename U = typename T::iterator>
	void	_swapPairs(U& it, const int elemSize) {
		U	end = it + elemSize;
		int	temp;

		for (; it < end; it++) {
			U	next = it + elemSize;

			temp = *it;
			*it = *next;
			*next = temp;
		}
		it += elemSize;
	};

	/* moves it after elemSize elements.
	 */
	template <typename T, typename U = typename T::iterator>
	void	_pushElem(U& it, T& tail, const int elemSize) {

	};

	/* moves it after elemSize elements.
	 */
	template <typename T, typename U = typename T::iterator>
	void	_binarySearchInsert(T& main, U& tail_it, const int elemSize,
		const int jacobNum) {

	};

	std::vector<int>	_vector;
	std::deque<int>		_deque;
	std::chrono::duration<double>	_timeVector;
	std::chrono::duration<double>	_timeDeque;
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

