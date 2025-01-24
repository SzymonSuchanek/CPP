/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:14 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void){
    std::cout << std::boolalpha;

    Point a(0, 0);
    Point b(0, 5);
    Point c(5, 0);

    std::cout << bsp(a, b, c, Point(1, 1)) << std::endl;
    std::cout << bsp(a, b, c, Point(1, 2)) << std::endl;

    return 0;
}
