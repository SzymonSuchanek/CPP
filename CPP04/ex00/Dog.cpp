
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

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
    std::cout << "Constructor called: Dog" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other) {
	std::cout << "Copy created: Dog" << std::endl;
}

Dog::~Dog() {
    std::cout << "Object destroyed: Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Copy assignment operator called: Dog" << std::endl;
    if (this != &other) {
		Animal::operator=(other);
	}
    std::cout << "Assignment: Dog!" << std::endl;
    return *this;
}

std::string Dog::getType() const {
	return type;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
