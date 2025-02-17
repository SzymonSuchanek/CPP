/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:01:24 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/17 20:52:19 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <limits>

class ScalarConverter {
	
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

public:

	virtual ~ScalarConverter();
	
	static void convert(std::string &str);

	class ImpossibleException : public std::exception {
		public: 
			const char *what() const throw();
	};
	
	class NonDisplayableException : public std::exception {
		public:
			const char *what() const throw();
	};
	
};

#endif
