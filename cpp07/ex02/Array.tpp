# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Array.tpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 17:13:40 by akolupae          #+#    #+#              #
#    Updated: 2026/05/26 17:13:42 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : Array(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _pointer(nullptr) {

	if (n > 0)
		this->_pointer = new T[n];

}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _pointer(nullptr) {

	*this = other;
}

template <typename T>
Array<T>&	Array<T>::operator= (const Array& other) {

	if (*this != other) {
		if (this->_pointer != nullptr)
			delete[] this->_pointer;
		this->_size = other._size;
		this->_pointer = new T[other._size];
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_pointer[i] = other._pointer[i];
		}
	}
}

template <typename T>
Array<T>::~Array(void) {

	if (this->_pointer != nullptr)
		delete[] this->_pointer;
}

template <typename T>
unsigned int	Array<T>::size(void) const {
	return (this->_size);
}
