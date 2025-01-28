/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/28 12:05:59 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure() : AMateria("cure") {}
	Cure(const Cure &other) : AMateria(other) {}
	Cure &operator=(const Cure &other);
	virtual ~Cure() {}

	std::string const & getType() const { return type; }
	AMateria* clone() const { return new Cure(*this); }
	void use(ICharacter& target);

};

#endif
