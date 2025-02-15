
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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

class Bureaucrat;

class AForm {
	
private:

	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;

public:

	AForm();
	AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	virtual std::string getName() const;
	virtual bool getStatus() const;
	virtual int getGradeToSign() const;
	virtual int getGradeToExec() const;
	virtual void beSigned(const Bureaucrat &b);
	virtual void execute( Bureaucrat const &executor ) const = 0;
	void checkExec(const Bureaucrat &executor ) const;

	class GradeTooHighException : public std::exception	{
		public:
			const char	*what(void) const throw();
	};
	
	class GradeTooLowException : public	std::exception {
		public:
			const char	*what(void) const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
			const char	*what(void) const throw();
	};

	class FileNotOpenException : public std::exception {
		public:
			const char	*what(void) const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
