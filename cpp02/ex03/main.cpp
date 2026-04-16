/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/15 22:26:51 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool		bsp(Point const a, Point const b, Point const c, Point const point);
static void	check_bsp(Point const a, Point const b, Point const c,
	Point const point);

int	main(void) {
	check_bsp(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0));
	check_bsp(Point(0, 0), Point(3, 0), Point(2, 2), Point(1.5, 1.5));
	check_bsp(Point(0, 0), Point(3, 0), Point(2, 2), Point(2, 1));
	check_bsp(Point(0, 0), Point(3, 0), Point(2, 2), Point(2, 2));
	check_bsp(Point(-1.5, -7.23), Point(4.67, -1), Point(-0.2, 0), Point(4.35, -1));

	return 0;
}

static void	check_bsp(Point const a, Point const b, Point const c,
	Point const point) {
	std::cout << "\nTriangle:"
		<< "\na(" << a.getX() << "," << a.getY() << ")"
		<< "\nb(" << b.getX() << "," << b.getY() << ")"
		<< "\nc(" << c.getX() << "," << c.getY() << ")" << std::endl;
	std::cout << "\nPoint: "
		<< "(" << point.getX() << "," << point.getY() << ")" << std::endl;
	std::cout << "\nPoint is inside: ";
	if (bsp(a, b, c, point))
		std::cout << "true\n";
	else
		std::cout << "false\n";
	std::cout << std::endl;
}
