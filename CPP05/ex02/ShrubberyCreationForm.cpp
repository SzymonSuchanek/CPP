
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/22 12:41:17 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 0, 145, 13), _target("TARGET_PLACEHOLDER") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 0, 145, 13), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other.getName(), other.getStatus(), other.getGradeToExec(), other.getGradeToSign()), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->AForm::checkExec(executor);
	
	std::fstream outputFile;
	outputFile.open((this->_target + "_shrubbery").c_str(), std::ios::out);

	if (!outputFile)
		throw AForm::FileNotOpenException();

	std::cout<< ",d" << std::endl;                                     
	std::cout<< "88" << std::endl;                                     
	std::cout<< "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba," << std::endl;
	std::cout<< "88    88P'      *Y8 a8P_____88 a8P_____88" << std::endl;
	std::cout<< "88    88            8PP******* 8PP*******" << std::endl;
	std::cout<< "88,   88            *8b,   ,aa *8b,   ,aa" << std::endl;
	std::cout<< "*Y888 88             `*Ybbd8*'  `*Ybbd8*'" << std::endl;
    
	outputFile.close();
}
