/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/22 14:11:12 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.cpp"

class Point {

private:

	const Fixed x;
	const Fixed y;

public:

	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	~Point();
	Point &operator=(const Point &other);

	Fixed getX() const;
	Fixed getY() const;
	
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
