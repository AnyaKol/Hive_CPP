/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:54:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/21 12:28:35 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T, typename U>
constexpr U	easyfind(T& arr, int val) {

	U	first = arr.begin();
	U	last = arr.end();

	for (; first != last; ++first) {
		if ( *first == val )
			return (first);
	}

	return (last);
}
