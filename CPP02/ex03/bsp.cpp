/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/23 16:46:52 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed sign(Point const p1, Point const p2, Point const p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

static bool isPointOnEdge(Point const p1, Point const p2, Point const point) {
	// crossProduct is the z component of the cross product of two vectors, cross product is 0 if vectors are parallel,
	// cross product is positive if vectors are in the counter clockwise direction, negative if vectors are in the
	// clockwise direction
    Fixed crossProduct = (point.getY() - p1.getY()) * (p2.getX() - p1.getX()) - (point.getX() - p1.getX()) * (p2.getY() - p1.getY());
    if (crossProduct != Fixed(0)) 
        return false;

	// dotProduct shows relative position of point to the vector, before or after the vector, it is scalar of two vectors,
	// scalar is projection of one vector to another, scalar is positive if vectors are in the same direction,
	// negative if vectors are in the opposite direction, 0 if vectors are perpendicular	
    Fixed dotProduct = (point.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (point.getY() - p1.getY()) * (p2.getY() - p1.getY());
    if (dotProduct < Fixed(0)) 
        return false;

	// squaredLength of the vector, squared length is the dot product of the vector with itself, it shows the length of the vector
	// if they are parallel and dot product is greater than squared length of the vector, point is after the vector,
	// projection of the point to the vector1 is further than the length of the vector2	
    Fixed squaredLengthBA = (p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY());
    if (dotProduct > squaredLengthBA) 
        return false;
		
    return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    if (isPointOnEdge(a, b, point) || isPointOnEdge(b, c, point) || isPointOnEdge(c, a, point)) 
        return false;

    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
