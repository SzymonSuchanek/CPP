
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

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

class Bureaucrat;

class Form {
	
private:

	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;

public:

	Form();
	Form(std::string name, bool isSigned, int gradeToSign, int gradeToExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	virtual ~Form();

	std::string getName() const;
	bool getStatus() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
	
	class GradeTooLowException : public	std::exception
	{
		public:
			const char	*what(void) const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
