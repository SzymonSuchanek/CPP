/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/23 13:45:35 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

# include <iostream>

class Zombie {

public:

	Zombie();
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
	void setName(const std::string& newName);

private:
	
	std::string name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
