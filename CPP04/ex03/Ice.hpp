/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/28 12:05:52 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice() : AMateria("ice") {}
	Ice(const Ice &other) : AMateria(other) {}
	Ice &operator=(const Ice &other);
	virtual ~Ice() {}

	std::string const & getType() const { return type; }
	AMateria* clone() const { return new Ice(*this); }
	void use(ICharacter& target);

};

#endif
