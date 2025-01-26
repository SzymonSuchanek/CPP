
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

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	ClapTrap::hitPoints = FragTrap::hitPoints;
	ClapTrap::energyPoints = ScavTrap::energyPoints;
	ClapTrap::attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other.name) {
	*this = other;
	std::cout << "DiamondTrap " << name << " copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other.name;
	}
    std::cout << "DiamondTrap " << name << " assigned!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
