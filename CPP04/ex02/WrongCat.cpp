
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

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
    std::cout << "Constructor called: WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other) {
	std::cout << "Copy created: WrongCat" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Object destroyed: WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << "Copy assignment operator called: WrongCat" << std::endl;
    if (this != &other) {
		WrongAnimal::operator=(other);
	}
    std::cout << "Assignment: WrongCat!" << std::endl;
    return *this;
}

std::string WrongCat::getType() const {
	return type;
}

void WrongCat::makeSound() const {
	std::cout << "WrongMeow!" << std::endl;
}
