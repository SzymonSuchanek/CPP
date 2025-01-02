/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:41:48 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/02 16:58:27 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    int labelWidth = 40;
    int valueWidth = 20;

    std::cout << std::left << std::setw(labelWidth) << "The address of string is:" 
              << std::right << std::setw(valueWidth) << &string << std::endl;

    std::cout << std::left << std::setw(labelWidth) << "The address stored in stringPTR is:" 
              << std::right << std::setw(valueWidth) << stringPTR << std::endl;

    std::cout << std::left << std::setw(labelWidth) << "The address represented by stringREF is:" 
              << std::right << std::setw(valueWidth) << &stringREF << std::endl;

    std::cout << std::left << std::setw(labelWidth) << "The value of string is:" 
              << std::right << std::setw(valueWidth) << string << std::endl;

    std::cout << std::left << std::setw(labelWidth) << "The value pointed to by stringPTR is:" 
              << std::right << std::setw(valueWidth) << *stringPTR << std::endl;

    std::cout << std::left << std::setw(labelWidth) << "The value represented by stringREF is:" 
              << std::right << std::setw(valueWidth) << stringREF << std::endl;

    return 0;
}