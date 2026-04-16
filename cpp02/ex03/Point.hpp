/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:04:10 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/16 14:04:16 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	bool			operator== (const Point& other) const;
	Fixed const&	getX(void) const;
	Fixed const&	getY(void) const;

private:

	Fixed const	_x;
	Fixed const	_y;

};

#endif
