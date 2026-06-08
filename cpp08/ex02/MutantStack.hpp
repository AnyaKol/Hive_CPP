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

// Using C++11 to use U as default template argument.
template <typename T>
class	MutantStack {

public:

	std::deque<T>::iterator		begin(void);
	std::deque<T>::const_iterator	begin(void) const;
	std::deque<T>::const_iterator	cbegin(void) const noexcept;

	std::deque<T>::iterator		end(void);
	std::deque<T>::const_iterator	end(void) const;
	std::deque<T>::const_iterator	cend(void) const noexcept;

	std::deque<T>::reverse_iterator		rbegin(void);
	std::deque<T>::const_reverse_iterator	rbegin(void) const;
	std::deque<T>::const_reverse_iterator	crbegin(void) const noexcept;

	std::deque<T>::reverse_iterator		rend(void);
	std::deque<T>::const_reverse_iterator	rend(void) const;
	std::deque<T>::const_reverse_iterator	crend(void) const noexcept;

private:

	std::deque<T>	_container;
}
