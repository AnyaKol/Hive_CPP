/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:25:03 by akolupae          #+#    #+#             */
/*   Updated: 2026/06/05 19:26:05 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Span {

public:

	Span(void);
	Span(unsigned int N);
	Span(const Span& other);
	const Span& operator=(const Span& other);
	~Span();

	const unsigned int&	getMaxSize(void) const;
	const unsigned int&	getSize(void) const;
	const int*			getPtr(void) const;
	int&				operator[](unsigned int pos);
	const int&			operator[](unsigned int pos) const;

	void			addNumber(int num);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

	class	MaxSizeReached;
	class	SpanTooShort;

	template <typename T, typename U = typename T::iterator>
	void	addNumber(T arr, int count) {

		U	first = arr.begin();
		U	last = first + count;
	
		for (; first != last; first++)
			addNumber(*first);
	}

	template <typename T, typename U = typename T::iterator>
	void	addNumber(T arr) {

		U	first = arr.begin();
		U	last = arr.end();
	
		for (; first != last; first++)
			addNumber(*first);
	}

private:

	unsigned int	_max_size;
	unsigned int	_size;
	int*			_ptr;

	unsigned int	_span(int a, int b) const;
};

class Span::MaxSizeReached : public std::exception {

public:

	MaxSizeReached() {};
	~MaxSizeReached() {};

	const char*	what(void) const noexcept override;

private:

	static const std::string	_msg;
};

class Span::SpanTooShort : public std::exception {

public:

	SpanTooShort() {};
	~SpanTooShort() {};

	const char*	what(void) const noexcept override;

private:

	static const std::string	_msg;
};
