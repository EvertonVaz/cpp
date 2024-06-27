/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:22:19 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/27 15:53:21 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	ft_input(std::string msg){
	std::string	input;

	if (std::cin.eof() == 1)
		return ("");
	std::cout << msg;
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << RED << "Invalid input" << END << std::endl;
		return (ft_input(msg));
	}
	return (input);
}

Contact createContact(void){
	Contact	contact;

	contact.setFirstName(ft_input("Enter the first name: "));
	contact.setLastName(ft_input("Enter the last name: "));
	contact.setNickname(ft_input("Enter the nickname: "));
	contact.setPhoneNumber(ft_input("Enter the phone number: "));
	contact.setDarkestSecret(ft_input("Enter the darkest secret: "));
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
		if (command == "3" || command == "EXIT" || std::cin.eof() == 1)
			break;
		else if (command == "1" || command == "ADD")
			phoneBook.addContact(createContact());
		else if (command == "2" || command == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << RED << "Invalid command" << END << std::endl;
		std::cout << std::endl;
	}
	return (0);
}