/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/28 13:28:31 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
#include "ICharacter.hpp"

class AMateria {

protected:

	std::string type;

public:

	AMateria() : type("") {}
	AMateria(const AMateria &other) : type(other.type) {}
	AMateria(std::string const & type) : type(type) {}
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria() {}

	std::string const & getType() const { return type; }
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;

};

#endif
