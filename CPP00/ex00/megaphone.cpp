/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:51:42 by ssuchane          #+#    #+#             */
/*   Updated: 2024/12/17 19:07:45 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; j < std::strlen(argv[i]); j++)
			{
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
			std::cout << '\n';
		}
	}
	return (0);
}
