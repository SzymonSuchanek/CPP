/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/04/25 19:21:23 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp" 

int main() {
    std::srand(std::time(NULL));

    std::cout << "==== Basic Test ====" << std::endl;
    try {
        RPN sp = RPN(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest RPN: " << sp.shortestRPN() << std::endl;
        std::cout << "Longest RPN: " << sp.longestRPN() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== Exception Test (Add beyond limit) ====" << std::endl;
    try {
        RPN sp(2);
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
    } catch (std::exception &e) {
        std::cout << "Expected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== Exception Test (Not enough numbers) ====" << std::endl;
    try {
        RPN sp(1);
        sp.addNumber(42);
        std::cout << "Shortest RPN: " << sp.shortestRPN() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Expected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== Bulk Insert Test (10,000 Random Numbers) ====" << std::endl;
    try {
        RPN sp(10000);
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; ++i)
            bigVec.push_back(rand());
        sp.addNumbers(bigVec.begin(), bigVec.end());

        std::cout << "Shortest RPN: " << sp.shortestRPN() << std::endl;
        std::cout << "Longest RPN: " << sp.longestRPN() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== Ordered Input Test (ascending) ====" << std::endl;
    try {
        RPN sp(1000);
        for (int i = 0; i < 1000; ++i)
            sp.addNumber(i);

        std::cout << "Shortest RPN: " << sp.shortestRPN() << std::endl; // Expected: 1
        std::cout << "Longest RPN: " << sp.longestRPN() << std::endl;   // Expected: 999
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n==== All Identical Numbers Test ====" << std::endl;
    try {
        RPN sp(5);
        for (int i = 0; i < 5; ++i)
            sp.addNumber(42);

        std::cout << "Shortest RPN: " << sp.shortestRPN() << std::endl; // Expected: 0
        std::cout << "Longest RPN: " << sp.longestRPN() << std::endl;   // Expected: 0
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}