
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

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Constructor called: Brain" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy constructor called: Brain" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
}

Brain::~Brain() {
    std::cout << "Object destroyed: Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Copy assignment operator called: Brain" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
