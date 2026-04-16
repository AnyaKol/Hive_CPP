
#include "Point.hpp"

// Default constructor
Point::Point(void) : _x(Fixed(0.0f)), _y(Fixed(0.0f)) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Pont(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {
	std::cout << "Int constructor called" << std::endl;
}

// Copy constructor
Point::Point(const Point& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator overload
Point&	Point::operator= (const Point& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other) {
		this->_x = other.x;
		this->_y = other.y;
	}

	return (*this);	
}

// Destructor
Point::~Point(void) {
	std::cout << "Destructor called" << std::endl;
}
