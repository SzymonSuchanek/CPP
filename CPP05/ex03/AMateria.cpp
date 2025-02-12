/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/12 13:52:56 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria() : type("") {}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return type; }