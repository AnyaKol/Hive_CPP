/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:02:53 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/16 14:03:51 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	getArea(Point const& a, Point const& b, Point const& c);

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	areaABPoint;
	Fixed	areaBCPoint;
	Fixed	areaACPoint;
	Fixed	areaABC;

	try {
		areaABPoint = getArea(a, b, point);
		areaBCPoint = getArea(b, c, point);
		areaACPoint = getArea(a, c, point);
		areaABC = getArea(a, b, c);
	}
	catch (int area) {
		return (false);
	}
	if (areaABPoint + areaBCPoint + areaACPoint == areaABC)
		return (true);
	return (false);
}

static Fixed	getArea(Point const& a, Point const& b, Point const& c) {
	Fixed	area;

	area = (a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY())
	);
	if (area.toFloat() < 0)
		area = Fixed(-area.toFloat());
	if (area == 0)
		throw (0);
	return (area);
}