/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:01:24 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/15 20:32:47 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <cctype> 
# include <cmath>
# include <climits>

class ScalarConverter {
	
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

public:

	virtual ~ScalarConverter();
	
	static void convert(std::string s);

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
