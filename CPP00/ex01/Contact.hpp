/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:14:38 by ssuchane          #+#    #+#             */
/*   Updated: 2024/12/29 19:28:22 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_HPP_
#define _CONTACT_HPP_

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContact(const std::string &fName, const std::string &lName, const std::string &nick, const std::string &phone, const std::string &secret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    void displayContact() const;
};

#endif