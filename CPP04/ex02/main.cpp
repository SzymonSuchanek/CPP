/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/28 11:05:02 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "==== Mandatory tests ====" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	
    const int arraySize = 6;
    const Animal* animals[arraySize];
	
	std::cout << "\n==== Additional tests ====" << std::endl;
    for (int i = 0; i < arraySize / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; ++i) {
        animals[i] = new Cat();
    }

    std::cout << "\nAnimals making sounds:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        animals[i]->makeSound();
    }
	std::cout << std::endl;
	
    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

    std::cout << "\nAll animals deleted, program exiting." << std::endl;

	// This line should cause a compilation error
    // const Animal* animal = new Animal();

    return 0;
}
