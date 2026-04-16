
#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {

public:

	Point(void);
	Point(const float x, const float y);
	Point(const Point& other);
	Point&	operator= (const Point& other);
	~Point(void);

private:

	Fixed const	_x;
	Fixed const	_y;

};


#endif
