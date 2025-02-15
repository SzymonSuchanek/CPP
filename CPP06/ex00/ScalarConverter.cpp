/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:01:18 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/15 20:33:17 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { 
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::ImpossibleException::what() const throw() {
	return "The conversion is impossible.";
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
	return "The result is non displayable.";
}

void ScalarConverter::convert(std::string s) {
    char* end;
    
    // Convert to double
    double doubleValue = std::strtod(s.c_str(), &end);
    bool isFloat = (*end == 'f' && *(end + 1) == '\0'); // Check for float literal

    // Check if it is a valid float or double
    if (*end == '\0' || isFloat) {
        // Check if the value is NaN
        if (std::isnan(doubleValue)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
            return;
        }

        // Handle the float case
        float floatValue = static_cast<float>(doubleValue);

        // Convert to char
        if (floatValue >= 0 && floatValue <= 255 && std::isprint(static_cast<char>(static_cast<int>(floatValue)))) {
            std::cout << "char: '" << static_cast<char>(static_cast<int>(floatValue)) << "'" << std::endl;
        } else if (floatValue >= 0 && floatValue <= 255) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }

        // Convert to int
        int intValue = static_cast<int>(floatValue);
        std::cout << "int: " << intValue << std::endl;

        // Convert to float
        std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;

        // Convert to double
        std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}