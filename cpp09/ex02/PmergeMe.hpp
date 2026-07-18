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
	void	_sort(std::vector<int>& container, const int elem_size);
	void	_sort(std::deque<int>& container, const int elem_size);

	template <typename T, typename U = typename T::iterator>
	void	_swap_pairs(U it, const int elem_size) {
		U	end = it + elem_size;
		int	temp;

		for (; it < end; it++) {
			temp = *it;
			*it = *(it + elem_size);
			*(it + elem_size) = temp;
		}
	}

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

