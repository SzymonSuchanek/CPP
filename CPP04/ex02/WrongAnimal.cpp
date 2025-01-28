/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/26 13:07:46 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("") {
    std::cout << "Constructor called: WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : type(other.type) {
    std::cout << "Copy created: WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Object destroyed: WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "Copy assignment operator called: WrongAnimal" << std::endl;
    if (this != &other) {
		type = other.type;
	}
    std::cout << "Assignment: WrongAnimal!" << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}
