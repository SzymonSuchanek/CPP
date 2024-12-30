/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2024/12/30 20:05:56 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int hordeSize = 5;
    std::string name = "Zombie_Horde_Member";

    Zombie* horde = zombieHorde(hordeSize, name);

    if (horde) {
        for (int i = 0; i < hordeSize; ++i) {
            horde[i].announce();
        }
        delete[] horde; // Deallocate the horde
    } else {
        std::cout << "Invalid horde size!" << std::endl;
    }

    return 0;
}
