/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:31:32 by akolupae          #+#    #+#             */
/*   Updated: 2026/06/08 15:31:41 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Use "c" to address Container inside stack.
template <typename T, typename Container>
typename MutantStack<T, Container>
::iterator	MutantStack<T, Container>::begin(void) {
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_iterator	MutantStack<T, Container>::begin(void) const {
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_iterator	MutantStack<T, Container>::cbegin(void) const noexcept {
	return (this->c.cbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::iterator	MutantStack<T, Container>::end(void) {
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_iterator	MutantStack<T, Container>::end(void) const {
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_iterator	MutantStack<T, Container>::cend(void) const noexcept {
	return (this->c.cend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::reverse_iterator	MutantStack<T, Container>::rbegin(void) {
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_reverse_iterator	MutantStack<T, Container>::rbegin(void) const {
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_reverse_iterator	MutantStack<T, Container>::crbegin(void) const
noexcept {
	return (this->c.crbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::reverse_iterator	MutantStack<T, Container>::rend(void) {
	return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_reverse_iterator	MutantStack<T, Container>::rend(void) const {
	return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>
::const_reverse_iterator	MutantStack<T, Container>::crend(void) const
noexcept {
	return (this->c.crend());
}

