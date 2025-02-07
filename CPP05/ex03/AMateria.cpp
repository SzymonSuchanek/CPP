/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/28 13:18:53 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		type = other.type;
	return *this;
}
