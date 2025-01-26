
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

# include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) 
	: ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << name << " copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << name << " assigned!" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (hitPoints == 0)
		std::cout << "FragTrap " << name << " is dead!" << std::endl;
	else if (energyPoints == 0)
		std::cout << "FragTrap " << name << " does not have enough energy to attack!" << std::endl;
	else {
		std::cout << "FragTrap " << name << " attacks " << target << " causing " << attackDamage << " damage!" << std::endl;	
		energyPoints--;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name << " requested high five!" << std::endl;
}