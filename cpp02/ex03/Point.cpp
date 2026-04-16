/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:03:59 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/16 14:04:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point(void) : _x(Fixed(0.0f)), _y(Fixed(0.0f)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

// Copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

// Copy assignment operator overload
Point&	Point::operator= (const Point& other) {

	if (this != &other) {
		static Point	newPoint(other);

		return (newPoint);
	}

	return (*this);
}

// Destructor
Point::~Point(void) {}

// Overloading operator== for comparing points
bool	Point::operator== (const Point& other) const {
	return ( this->_x == other._x && this->_y == other._y );
}

// Getters for private attributes
Fixed const&	Point::getX(void) const {
	return (this->_x);
}

Fixed const&	Point::getY(void) const {
	return (this->_y);
}
