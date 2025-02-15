
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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
	
private:

	const std::string _name;
	int _grade;

public:

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	virtual ~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void upGrade();
	void downGrade();

	class GradeTooHighException : public std::exception	{
		public:
			const char	*what(void) const throw();
	};
	
	class GradeTooLowException : public	std::exception {
		public:
			const char	*what(void) const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
