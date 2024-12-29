/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:14:33 by ssuchane          #+#    #+#             */
/*   Updated: 2024/12/29 19:32:39 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::truncateField(const std::string &field) const {
	if (field.length() > 10) {
		return field.substr(0, 9) + ".";
	}
	return field;
}

void PhoneBook::addContact() {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name." << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: " << std::endl;
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "Error: All fields must be filled!" << std::endl;
		return;
	}

	contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	currentIndex = (currentIndex + 1) % 8;
	if (totalContacts < 8) {
		totalContacts++;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const {
	if (totalContacts == 0) {
		std::cout << "The phonebook is empty." << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < totalContacts; ++i) {
		std::cout << std::setw(10) << i << "|"
					<< std::setw(10) << truncateField(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncateField(contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncateField(contacts[i].getNickname()) << std::endl;
	}

	std::string input;
	std::cout << "Enter the index of the contact to display." << std::endl;
	std::getline(std::cin, input);

	bool isNumber = true;
	for (std::size_t i = 0; i < input.length(); ++i) {
		if (!std::isdigit(input[i])) {
			isNumber = false;
			break;
		}
	}
	
	int	index = 0;
	for (size_t i = 0; i < input.length(); ++i) {
		index = index * 10 + (input[i] - '0');
	}

	if (input.empty() || !isNumber) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	if (index < 0 || index > 8) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	contacts[index].displayContact();
}
