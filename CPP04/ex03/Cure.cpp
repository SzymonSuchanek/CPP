/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/28 12:08:19 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals" << target.getName() << " wounds *" << std::endl;
}
