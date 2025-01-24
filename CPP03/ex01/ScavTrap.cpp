
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

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) 
	: ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap " << name << " copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << name << " assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " is dead!" << std::endl;
	else if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " does not have enough energy to attack!" << std::endl;
	else {
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " damage!" << std::endl;	
		energyPoints--;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
