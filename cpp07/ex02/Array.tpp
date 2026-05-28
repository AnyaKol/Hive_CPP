#include "Array.hpp"

// For std::out_of_range, inherites from std::exception.
#include <stdexcept>

template <typename T>
Array<T>::Array(void) : Array(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _pointer(nullptr) {

	if (n > 0) {
		this->_pointer = new T[n];
		for (unsigned int i = 0; i < n; i++)
			this->_pointer[i] = T{};
	}

}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _pointer(nullptr) {

	*this = other;
}

template <typename T>
Array<T>&	Array<T>::operator= (const Array& other) {

	if (this != &other) {
		if (this->_pointer != nullptr)
			delete[] this->_pointer;
		this->_size = other._size;
		this->_pointer = new T[other._size];
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_pointer[i] = other._pointer[i];
		}
	}

	return (*this);
}

template <typename T>
Array<T>::~Array(void) {

	if (this->_pointer != nullptr)
		delete[] this->_pointer;
}

const std::string outRange = "Index is out of range.";

template <typename T>
T&	Array<T>::operator[](unsigned int pos) {

	if (pos >= this->_size)
		throw std::out_of_range(outRange);

	return (this->_pointer[pos]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int pos) const {

	if (pos >= this->_size)
		throw std::out_of_range(outRange);

	return ( const_cast<const T>(this->_pointer[pos]) );
}

template <typename T>
unsigned int	Array<T>::size(void) const {
	return (this->_size);
}
