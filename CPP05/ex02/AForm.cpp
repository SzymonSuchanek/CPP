/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/12 14:26:30 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what(void) const throw() {
	return "Exception: Grade too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return "Exception: Grade too low!";
}

AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1), _target("") {}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec, std::string target) 
	: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _target(target) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 0 || gradeToExec < 0)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _target(other._target) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)	{
		this->_isSigned = other._isSigned;
		return *this;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }

bool AForm::getStatus() const { return _isSigned; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExec() const { return _gradeToExec; }

std::string AForm::getTarget() const { return _target; }

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    if (form.getStatus())
        out << "Form: " << form.getName() << " is signed";
    else
        out << "Form: " << form.getName() << " is not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign, and grade " << form.getGradeToExec() << " to execute";
    return out;
}
