
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:11:55 by ssuchane          #+#    #+#             */
/*   Updated: 2025/01/22 12:41:17 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime> 


class Base {
	
	public:
	
	virtual ~Base() {}
	
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {
	int randNum = std::rand() % 3;
	
    if (randNum == 0)
	return new A();
    else if (randNum == 1)
	return new B();
    else
	return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (...) {}
	
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (...) {}
}

#endif
