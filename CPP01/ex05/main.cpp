/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:41:48 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/04 17:28:27 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;
	std::string level;
	
    while (true) 
    {
        std::cout << "Enter complaint level (DEBUG, INFO, WARNING, ERROR) or 'end' to quit." << std::endl;
		if (!std::getline(std::cin, level)) {
            std::cout << std::endl; 
            break;
        }

        if (level == "end") {
            break;
        }

        harl.complain(level);
    }

    return 0;
}
