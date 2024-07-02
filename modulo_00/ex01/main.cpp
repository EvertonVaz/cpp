/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:22:19 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/01 12:09:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		if (std::cin.eof() == 1)
			break ;
		std::cout << "Enter a command: \n1 - ADD\n2 - SEARCH\n3 - EXIT\n";
		std::getline(std::cin, command);

		if (command == "1" || command == "ADD")
			phoneBook.addContact(createContact());
		else if (command == "2" || command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "3" || command == "EXIT")
			break;
		else
			std::cout << RED << "Invalid command" << END << std::endl;
		std::cout << std::endl;
	}
	return (0);
}