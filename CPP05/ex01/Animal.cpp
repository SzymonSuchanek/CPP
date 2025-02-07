/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/26 13:07:46 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type("") {
    std::cout << "Constructor called: Animal" << std::endl;
}

Animal::Animal(const Animal& other)
    : type(other.type) {
    std::cout << "Copy created: Animal" << std::endl;
}

Animal::~Animal() {
    std::cout << "Object destroyed: Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Copy assignment operator called: Animal" << std::endl;
    if (this != &other) {
		type = other.type;
	}
    std::cout << "Assignment: Animal!" << std::endl;
    return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}
