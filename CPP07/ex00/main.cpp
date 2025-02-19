/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/19 02:26:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp" 

int main() {
    int a = 5, b = 10;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;

    std::cout << "min(5, 10) = " << min(5, 10) << std::endl;
    std::cout << "min(10, 5) = " << min(10, 5) << std::endl;
    std::cout << "min(5, 5) = " << min(5, 5) << std::endl;

    std::cout << "max(5, 10) = " << max(5, 10) << std::endl;
    std::cout << "max(10, 5) = " << max(10, 5) << std::endl;
    std::cout << "max(5, 5) = " << max(5, 5) << std::endl;

    return 0;
}
