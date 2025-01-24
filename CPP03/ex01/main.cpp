/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/24 17:32:47 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap hero("Rob");

    hero.attack("Monster");
    hero.takeDamage(33);
    hero.beRepaired(35);
    
    hero.attack("Boss");
    hero.takeDamage(500);
    hero.beRepaired(10);

    hero.guardGate();

    return 0;
}
