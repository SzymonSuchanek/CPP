/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/02/07 12:23:03 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure();

	std::string const & getType() const;
	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif
