/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/20 18:49:48 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>

struct Data;

class Serializer {

public:

	Serializer(void) = delete;
	Serializer(const Serializer& other) = delete;
	Serializer(Serializer&& other) noexcept = delete;
	Serializer&	operator= (const Serializer& other) = delete;
	Serializer&	operator= (Serializer&& other) noexcept = delete;
	~Serializer(void) {};

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
