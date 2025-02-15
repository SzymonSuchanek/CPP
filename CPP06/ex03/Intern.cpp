/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:25:10 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/13 17:56:48 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { 
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::newShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::newPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::newRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makeForm(std::string form, std::string target) {
	std::string forms[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newPresidential, &Intern::newRobotomy};
	int i = 0;

	while (i < 4 && forms[i].compare(form) != 0)
		i++;
	if (i < 3) {
		std::cout << "Intern creates " << forms[i] << std::endl;
		return (this->*p[i])(target);
	}
	else
		std::cout << "Exception: " << form << " is not a valid name for a form!" << std::endl;
	return NULL;
}
