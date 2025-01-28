
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

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
    std::cout << "Constructor called: Cat" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& other)
	: Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Copy created: Cat" << std::endl;
}

Cat::~Cat() {
	delete brain;
    std::cout << "Object destroyed: Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Copy assignment operator called: Cat" << std::endl;
    if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
    std::cout << "Assignment: Cat!" << std::endl;
    return *this;
}

std::string Cat::getType() const {
	return type;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
