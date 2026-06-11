/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:54:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/21 12:28:35 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T, typename Container = std::deque<T>>
class	MutantStack : public std::stack<T> {

public:

	typedef typename Container::iterator				iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator		begin(void);
	const_iterator	begin(void) const;
	const_iterator	cbegin(void) const noexcept;

	iterator		end(void);
	const_iterator	end(void) const;
	const_iterator	cend(void) const noexcept;

	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	const_reverse_iterator	crbegin(void) const noexcept;

	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;
	const_reverse_iterator	crend(void) const noexcept;
};
