/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/07 16:30:54 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	std::cout << "-------------------Test one-------------------" << std::endl;
	Bureaucrat a;
	Form FormA("A5", 0, 75, 75);

	std::cout << "Bureaucrat: a will attempt to sign the form: " << FormA.getName() << std::endl;
	std::cout << "And the result was: " << FormA.getStatus() << std::endl << std::endl;
	a.signForm(FormA);

	std::cout << "-------------------Test two-------------------" << std::endl;
	Bureaucrat b("John", 150);
	Form FormB("C1", 0, 75, 75);
	
	std::cout << "Bureaucrat: " << b.getName() << " will attempt to sign the form: " << FormA.getName() << std::endl;
	std::cout << "And the result was:" << std::endl;
	b.signForm(FormB);

	// try	{
	// 	Form tooHigh("TooHigh", 0, 0, 10);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << e.what() << '\n' << std::endl;
	// }

	// try	{
	// 	Form tooHigh("TooHigh", 0, 10, 0);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << e.what() << '\n' << std::endl;
	// }

	// try	{
	// 	Form tooLow("TooLow", 0, 151, 140);
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n' << std::endl;
	// }

	// try	{
	// 	Form tooLow("TooLow", 0, 130, 151);
	// }
	// catch (const std::exception& e)	{
	// 	std::cerr << e.what() << '\n';
	// }
}
