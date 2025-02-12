/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/12 13:53:17 by ssuchane         ###   ########.fr       */
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

	AMateria() : type("");
	AMateria(const AMateria &other);
	AMateria(std::string const & type);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const & getType();
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;

};

#endif
