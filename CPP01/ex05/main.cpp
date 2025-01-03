/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:41:48 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/03 17:31:26 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Arguments:\n1. filename\n2. string to be replaced\n3. string to replace with" << std::endl;
		return 1;
	}
	
	std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

	if (s1.empty()) {
        std::cerr << "Error: string to be replaced cannot be empty." << std::endl;
        return 1;
    }

	std::ifstream inputFile(filename.c_str());
    if (!inputFile)	{
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

	std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();

	replace(content, s1, s2);

    std::ofstream outputFile((filename + "_replace").c_str());
    if (!outputFile) {
        std::cerr	<< "Error: Could not create output file " 
					<< filename << "_replace" << std::endl;
        return 1;
    }

    outputFile << content;
    outputFile.close();
	
	return 0;
}
