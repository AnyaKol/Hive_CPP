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
#include <ranges>

// Can use 'class' keyword instead of 'typename'
template <typename T>
void	swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
};

// Creating concept using 'requires' expression.
template <typename T>
concept Comparable = requires (T a, T b) {
	a < b;
	a <= b;
};

/* Using concept by calling 'requires' clause.
 * Could do expression + clause:
 * requires requires (T a, T b) {...};
 */
template <typename T>
requires Comparable<T>
T	min(T a, T b) {
	return ( (a < b) ? a : b );
};

template <typename T>
requires Comparable<T>
T	max(T a, T b) {
	return ( (a <= b) ? b : a );
};
