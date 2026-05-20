/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/20 18:49:41 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
//#include "Data.hpp"
struct Data;

uintptr_t	Serializer::serialize(Data* ptr) {
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return ( reinterpret_cast<Data*>(raw) );
}
