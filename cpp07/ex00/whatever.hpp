/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:54:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/21 10:34:15 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// concepts: since C++20
// Allows to explicitly list template requirements.
#include <concepts>

// Can use 'class' keyword instead of 'typename'
template <typename T>
requires std::swappable<T>
constexpr void	swap(T& a, T& b) {
	T temp;

	temp = a;
	a = b;
	b = temp;
};

template <typename T>
requires std::totally_ordered<T>
constexpr T	min(T a, T b) {
	return ( (a < b) ? a : b );
};

template <typename T>
requires std::totally_ordered<T>
constexpr T	max(T a, T b) {
	return ( (a <= b) ? b : a );
};
