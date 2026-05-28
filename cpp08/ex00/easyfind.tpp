#include "easyfind.hpp"

// For std::out_of_range, inherites from std::exception.
#include <stdexcept>

template <typename T>
int&	easyfind(T arr, int val) {

	for (unsigned int i = 0; i < arr.size(); i++) {
		if ( arr[i] == val )
			return (arr[i]);
	}

	throw (val);
}