/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:25:10 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/15 18:22:16 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	
public:

	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	virtual ~Intern();

	AForm*	newShrubbery(std::string target);
	AForm*	newPresidential(std::string target);
	AForm*	newRobotomy(std::string target);
	AForm*	makeForm(std::string form, std::string target);

};

#endif
