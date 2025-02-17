/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/17 20:54:43 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    std::string input;
    if (argc == 1)
    {
        std::cout << "Enter a str to convert (e.g., '42', '42.0', 'a', 'hello'): ";
        std::cin >> input;
        if (std::cin.eof())
            return 1;
    }
    else
        input = argv[1];
    ScalarConverter::convert(input);

    return 0;
}