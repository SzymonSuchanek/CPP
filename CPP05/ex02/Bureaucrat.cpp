
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

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Exception: Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Exception: Grade too low!";
}

Bureaucrat::Bureaucrat(std::string name) : _name(name) {}

Bureaucrat::Bureaucrat() : _name("PLACE_FOR_NAME"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) 
	: _name(name) {
	if (grade > 150)
		throw (GradeTooLowException());
	if (grade < 1)
		throw (GradeTooHighException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)	{
		this->_grade = other._grade;
		return *this;
	}
	return *this;
}

std::string Bureaucrat::getName() const {return _name;}

int Bureaucrat::getGrade() const {return _grade;}

void Bureaucrat::upGrade() {
	if (this->_grade - 1 < 1)
		throw (GradeTooHighException());
	this->_grade--;
}

void Bureaucrat::downGrade() {
	if (this->_grade + 1 > 150)
		throw (GradeTooLowException());
	_grade++;
}

void Bureaucrat::signForm(AForm &form) const {
	if (form.getStatus())
		std::cout << "The form has already been signed." << std::endl;
	else {
		if (form.getGradeToSign() < this->_grade)
			std::cout << this->_name << " cannot sign " << form.getName() << ":grade too low" << std::endl;
		else
        	std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << "Bureaucrat: " << bureaucrat.getName() << std::endl;
	out << "Grade: " << bureaucrat.getGrade() << std::endl;
	return out;
}
