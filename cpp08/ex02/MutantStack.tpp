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

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return (this->std::stack<T>::std::deque<T>::begin());
}

//template <typename T>
//std::deque<T>::const_iterator	MutantStack::begin(void) const {
//	return (this->std::deque.begin());
//}

//template <typename T>
//std::deque<T>::const_iterator	MutantStack::cbegin(void) const noexcept {
//	return (this->std::deque.cbegin());
//}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return (this->std::stack<T>::std::deque<T>::end());
}

//template <typename T>
//std::deque<T>::const_iterator	MutantStack::end(void) const {
//	return (this->std::deque.end());
//}

//template <typename T>
//std::deque<T>::const_iterator	MutantStack::cend(void) const noexcept {
//	return (this->std::deque.cend());
//}

//template <typename T>
//std::deque<T>::reverse_iterator	MutantStack::rbegin(void) {
//	return (this->std::deque.rbegin());
//}

//template <typename T>
//std::deque<T>::const_reverse_iterator	MutantStack::rbegin(void) const {
//	return (this->std::deque.rbegin());
//}

//template <typename T>
//std::deque<T>::const_reverse_iterator	MutantStack::crbegin(void) const noexcept {
//	return (this->std::deque.crbegin());
//}

//template <typename T>
//std::deque<T>::reverse_iterator	MutantStack::rend(void) {
//	return (this->std::deque.rend());
//}

//template <typename T>
//std::deque<T>::const_reverse_iterator	MutantStack::rend(void) const {
//	return (this->std::deque.rend());
//}

//template <typename T>
//std::deque<T>::const_reverse_iterator	MutantStack::crend(void) const noexcept {
//	return (this->std::deque.crend());
//}

