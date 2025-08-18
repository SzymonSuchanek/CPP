/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:01:18 by ssuchane          #+#    #+#             */
/*   Updated: 2025/07/10 14:40:01 by marvin           ###   ########.fr       */
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

bool isChar(const std::string &str) {
    return (str.length() == 1 && !std::isdigit(str[0]));
}

bool isInt(const std::string &str) {
    for (size_t i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < str.length(); i++)
        if (!std::isdigit(str[i])) 
			return false;
	return true;
}

bool isFloat(const std::string &str) {
    return (str.find('.') != std::string::npos && str[str.length() - 1] == 'f');
}

bool isDouble(const std::string &str) {
    return (str.find('.') != std::string::npos && str[str.length() - 1] != 'f');
}

bool isSpecialstr(const std::string &str) {
    return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff");
}

void ScalarConverter::convert(std::string &str) {
    if (str.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    char *end = NULL;

    if (isSpecialstr(str)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << (str[str.size() - 1] != 'f' ? "f" : "") << std::endl;
        std::cout << "double: " << str.substr(0, str.size() - (str[str.size() - 1] == 'f' ? 1 : 0)) << std::endl;
        return;
    }

    if (isChar(str)) {
        char ch = str[0];
        std::cout << "char: '" << ch << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(ch) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(ch) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(ch) << std::endl;
        return;
    }

    if (isInt(str)) {
        long value = std::strtol(str.c_str(), &end, 10);
        if (*end != '\0' || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
            std::cout << "Error: Integer overflow" << std::endl;
            return;
        }

        int intValue = static_cast<int>(value);
        std::cout << "char: " << (std::isprint(intValue) ? "'" + std::string(1, static_cast<char>(intValue)) + "'" : "Non displayable") << std::endl;
        std::cout << "int: " << intValue << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(intValue) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(intValue) << std::endl;
        return;
    }

    if (isFloat(str)) {
        float value = std::strtof(str.c_str(), &end);
        if (*end != 'f') {
            std::cout << "Error: Invalid float input" << std::endl;
            return;
        }

        std::cout << "char: " << (std::isprint(static_cast<int>(value)) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) << std::endl;
        return;
    }

    if (isDouble(str)) {
        double value = std::strtod(str.c_str(), &end);
        if (*end != '\0') {
            std::cout << "Error: Invalid double input" << std::endl;
            return;
        }

        std::cout << "char: " << (std::isprint(static_cast<int>(value)) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
        return;
    }

    std::cout << "Error: Invalid input type" << std::endl;
}
