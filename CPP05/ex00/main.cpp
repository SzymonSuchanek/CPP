/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/07 11:59:37 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	try {
		Bureaucrat toolow("low", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try {
		Bureaucrat toohigh("high", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Bureaucrat a;
	std::cout << "Created " << a << std::endl;
	try	{
		a.upGrade();
	}
	catch (const std::exception& e)	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat b("b", 150);
	std::cout << "Created " << b << std::endl;
	try	{
		b.downGrade();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
