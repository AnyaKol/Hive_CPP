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

class PmergeMe {

public:

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe() {};

	int				getSize(void) const;
	const float&	getTimeVector(void) const;
	const float&	getTimeDeque(void) const;

	void	add(std::string_view str);
	void	printSequence(void) const;
	void	sort(void);

	static void	printError(std::string_view msg) noexcept;

	static const std::string	ERR_WINPUT;

	class	Exception;
	class	NameException;

private:

	std::vector<int>	_vector;
	std::deque<int>		_deque;
	float				_timeVector;
	float				_timeDeque;
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

