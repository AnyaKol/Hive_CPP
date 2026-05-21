/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:54:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/21 12:28:35 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// concepts: since C++20
// Allows to explicitly list template requirements.
#include <concepts>

// Can use 'class' keyword instead of 'typename'
template <typename T, typename U>
//requires std::<T>
void	iter(T& arr, const std::size_t len, U fun) {

	for (std::size_t i = 0; i < len; i++) {
		fun(arr[i]);
	}
};
