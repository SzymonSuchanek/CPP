/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/12 18:40:58 by ssuchane         ###   ########.fr       */
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

const char	*AForm::FormNotSignedException::what(void) const throw() {
	return ("Exception: Form not signed!");
}

const char	*AForm::FileNotOpenException::what(void) const throw() {
	return ("Exception: File couldn't be opened!");
}

AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec) 
	: _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 0 || gradeToExec < 0)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

AForm &AForm::operator=(const AForm &other) {
	(void)other;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return this->_name; }

bool AForm::getStatus() const { return this->_isSigned; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExec() const { return this->_gradeToExec; }

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    if (form.getStatus())
        out << "Form: " << form.getName() << " is signed";
    else
        out << "Form: " << form.getName() << " is not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign, and grade " << form.getGradeToExec() << " to execute";
    return out;
}

void AForm::checkExec(const Bureaucrat &executor ) const {
	if (this->_sign == false)
		throw (AForm::FormNotSigned());
	if (executor.getGrade() > this->getGradeE())
		throw (AForm::GradeTooLow());
}