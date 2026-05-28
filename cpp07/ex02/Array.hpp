/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:54:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/21 12:28:35 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array {

public:

	Array(void);
	Array(unsigned int n);
	Array(const Array& other);
	Array&	operator= (const Array& other);
	~Array(void);

	T&			operator[](unsigned int pos);
	const T&	operator[](unsigned int pos) const;

	unsigned int	size(void) const;

private:

	unsigned int	_size;
	T*				_pointer;
};
