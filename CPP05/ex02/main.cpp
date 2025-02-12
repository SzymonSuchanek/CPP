/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/12 18:21:39 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "-------------------Test one-------------------" << std::endl;
	Bureaucrat a("Eddy", 100);
	PresidentialPardonForm form1("Ed");

	std::cout << a.getName() << " attemps to sign the form " << form1.getName() << std::endl;
	a.signForm(form1);
	if (!a.executeForm(form1))
		form1.execute(a);
	
	std::cout << std::endl;
	
	// std::cout << "-------------------Test two-------------------" << std::endl;
	// Bureaucrat b("John", 150);
	// AForm FormB("B1", 0, 75, 75, "");
	
	// std::cout << b.getName() << " attemps to sign the form " << FormA.getName() << std::endl;
	// b.signForm(FormB);
	// std::cout << std::endl;

	// std::cout << "-------------------Test three-------------------" << std::endl;
	// Bureaucrat c;
	// Bureaucrat d("Bob", 100);
	// AForm FormC("C8", 0, 1, 1, "");
	// AForm FormD("D3", 0, 80, 80, "");
	
	// try {
	// 	c.signForm(FormC);
	// 	d.signForm(FormD);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << '\n';
	// }
	
	return 0;
}
