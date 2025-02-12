
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
	
protected:

	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;
	std::string _target;

public:

	AForm();
	AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec, std::string target);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	virtual std::string getName() const;
	virtual bool getStatus() const;
	virtual int getGradeToSign() const;
	virtual int getGradeToExec() const;
	virtual std::string getTarget() const;
	virtual void beSigned(const Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
