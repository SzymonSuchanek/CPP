/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/12 13:28:18 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what(void) const throw() {
	return "Exception: Grade too high!";
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return "Exception: Grade too low!";
}

Form::Form() : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExec) 
	: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 0 || gradeToExec < 0)
		throw GradeTooHighException();
}

Form::Form(const Form &other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

Form &Form::operator=(const Form &other) {
	if (this != &other)	{
		this->_isSigned = other._isSigned;
		return *this;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }

bool Form::getStatus() const { return _isSigned; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExec() const { return _gradeToExec; }

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    if (form.getStatus())
        out << "Form: " << form.getName() << " is signed";
    else
        out << "Form: " << form.getName() << " is not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign, and grade " << form.getGradeToExec() << " to execute";
    return out;
}
