/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:22:19 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/26 15:20:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	_input(std::string msg){
	std::string	input;

	std::cout << msg;
	std::getline(std::cin, input);
	if (std::cin.eof() == 1)
		exit(0);
	if (input == "")
	{
		std::cout << RED << "Invalid input" << END << std::endl;
		return (_input(msg));
	}
	return (input);
}

Contact createContact(void){
	Contact	contact;

	contact.setFirstName(_input("Enter the first name: "));
	contact.setLastName(_input("Enter the last name: "));
	contact.setNickname(_input("Enter the nickname: "));
	contact.setPhoneNumber(_input("Enter the phone number: "));
	contact.setDarkestSecret(_input("Enter the darkest secret: "));
	return (contact);
}

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command: \n1 - ADD\n2 - SEARCH\n3 - EXIT\n";
		std::getline(std::cin, command);
		if (command == "1" || command == "ADD")
			phoneBook.addContact(createContact());
		else if (command == "2" || command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "3" || command == "EXIT" || std::cin.eof() == 1)
			break;
		else
			std::cout << RED << "Invalid command" << END;
		std::cout << std::endl;
	}
	return (0);
}