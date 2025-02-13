/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/13 15:43:01 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	AForm *shrubbery = new ShrubberyCreationForm("home");
	Bureaucrat john("John", 1);
	Bureaucrat andrew("Andrew", 140);

	john.executeForm(*shrubbery);
	std::cout << std::endl;
	john.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	std::cout << john << std::endl;
	john.executeForm(*shrubbery);
	andrew.executeForm(*shrubbery);
	delete shrubbery;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm *robotomy = new RobotomyRequestForm("Dude");
	Bureaucrat vlad("Vlad", 1);

	vlad.executeForm(*robotomy);
	vlad.signForm(*robotomy);
	vlad.executeForm(*robotomy);
	vlad.executeForm(*robotomy);
	vlad.executeForm(*robotomy);
	vlad.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << std::endl;
	std::cout << std::endl;

	AForm *presidential = new PresidentialPardonForm("Corrector");
	Bureaucrat eve("Eve", 6);

	eve.executeForm(*presidential);
	eve.signForm(*presidential);
	eve.executeForm(*presidential);
	eve.upGrade();
	eve.executeForm(*presidential);
	delete presidential;
	
	return 0;
}
