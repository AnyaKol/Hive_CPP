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

iterator	MutantStack::begin(void) {
	return (this->_container.begin());
}

const_iterator	MutantStack::begin(void) const {
	return (this->_container.begin());
}

const_iterator	MutantStack::cbegin(void) const noexcept {
	return (this->_container.cbegin());
}

iterator	MutantStack::end(void) {
	return (this->_container.end());
}

const_iterator	MutantStack::end(void) const {
	return (this->_container.end());
}

const_iterator	MutantStack::cend(void) const noexcept {
	return (this->_container.cend());
}

reverse_iterator	MutantStack::rbegin(void) {
	return (this->_container.rbegin());
}

const_reverse_iterator	MutantStack::rbegin(void) const {
	return (this->_container.rbegin());
}

const_reverse_iterator	MutantStack::crbegin(void) const noexcept {
	return (this->_container.crbegin());
}

reverse_iterator	MutantStack::rend(void) {
	return (this->_container.rend());
}

const_reverse_iterator	MutantStack::rend(void) const {
	return (this->_container.rend());
}

const_reverse_iterator	MutantStack::crend(void) const noexcept {
	return (this->_container.crend());
}

