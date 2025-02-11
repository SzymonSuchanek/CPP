/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/11 15:52:56 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "-------------------Test one-------------------" << std::endl;
	Bureaucrat a;
	Form FormA("A5", 0, 75, 75);

	std::cout << a.getName() << " attemps to sign the form " << FormA.getName() << std::endl;
	a.signForm(FormA);
	std::cout << std::endl;
	
	std::cout << "-------------------Test two-------------------" << std::endl;
	Bureaucrat b("John", 150);
	Form FormB("B1", 0, 75, 75);
	
	std::cout << b.getName() << " attemps to sign the form " << FormA.getName() << std::endl;
	b.signForm(FormB);
	std::cout << std::endl;

	std::cout << "-------------------Test three-------------------" << std::endl;
	Bureaucrat c;
	Bureaucrat d("Bob", 100);
	Form FormC("C8", 0, 1, 1);
	Form FormD("D3", 0, 80, 80);
	
	try {
		c.signForm(FormC);
		d.signForm(FormD);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
