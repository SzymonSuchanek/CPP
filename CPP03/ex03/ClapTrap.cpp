/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/27 13:54:54 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
    std::cout << "ClapTrap " << name << " assigned!" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
	else if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " does not have enough energy to attack!" << std::endl;
	else {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " damage!" << std::endl;	
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is already dead, spare him!" << std::endl;
		return;
	}
	
	std::cout << "ClapTrap " << name << " took " << amount << " of damage!" << std::endl;
	if ((unsigned int)hitPoints <= amount) {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " died!" << std::endl;	
	}
	else {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " has " << hitPoints << " HP left!" << std::endl;	
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0){
		std::cout << "ClapTrap " << name << " can't repair while dead!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
		std::cout << "ClapTrap " << name << " does not have enough energy to restore HP! " << std::endl;
	else {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " restored " << amount << " HP!" << std::endl;
	}
	std::cout <<"ClapTrap " << name << " has " << energyPoints << " energy points left" << std::endl;
}
