/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/27 13:52:48 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap hero("Rob");

    hero.attack("Monster");
    hero.takeDamage(33);
    hero.beRepaired(35);
    
    hero.attack("Boss");
    hero.takeDamage(99);
    hero.beRepaired(10);

    hero.whoAmI();

    return 0;
}
