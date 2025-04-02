/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/04/02 12:07:57 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp" 

int main() {
    try {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);

        int value = 3;

        std::list<int>::iterator it = easyfind(lst, value);
        std::cout << "Value " << value << " found at position: " 
                  << std::distance(lst.begin(), it) << std::endl;
    } 
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        int value = 15;

        std::vector<int>::iterator it = easyfind(vec, value);
        std::cout << "Value " << value << " found at position: " 
                  << std::distance(vec.begin(), it) << std::endl;
    } 
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}