/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:47 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/28 13:24:18 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {

private:

	std::string _name;
	AMateria* inventory[4];

public:

	Character();
	Character(std::string name) : _name(name) {}
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character();

	std::string const & getName() const { return _name; }
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif
