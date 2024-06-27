/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:08:47 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/27 16:06:13 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentContactIndex(0), contactsCount(0) {};
PhoneBook::~PhoneBook() {};

void	PhoneBook::addContact(const Contact& contact) {
	_contacts[currentContactIndex] = contact;
    currentContactIndex = (currentContactIndex + 1) % 8;
    if (contactsCount < 8)
		contactsCount++;
}

static void print(std::string str) {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << "|";
}

void	PhoneBook::displayContact(void) const {
	int	i;

	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	i = 0;
	while (i < contactsCount)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		print(_contacts[i].getFirstName());
		print(_contacts[i].getLastName());
		print(_contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;;
}

void	PhoneBook::searchContact(void) const {
	std::string	index;
	int			i;

	if (contactsCount == 0)
	{
		std::cout << YELLOW << " No contacts available " << END << std::endl;
		return ;
	}
	displayContact();
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, index);
	if (std::cin.eof() == 1)
		return;
	i = std::atoi(index.c_str()) - 1;
	if (i >= 0 && i < contactsCount)
	{
		std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
		std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
		std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
	}
	else
		std::cout << RED << "Invalid index" << END << std::endl;
	std::cout << std::endl;
}
