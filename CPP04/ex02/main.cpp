/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/25 14:42:17 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	FragTrap hero("Rob");

    hero.attack("Monster");
    hero.takeDamage(33);
    hero.beRepaired(35);
    
    hero.attack("Boss");
    hero.takeDamage(500);
    hero.beRepaired(10);

    hero.highFivesGuys();

    return 0;
}
