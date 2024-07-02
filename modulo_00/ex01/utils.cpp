/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:06:17 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/01 11:06:23 by egeraldo         ###   ########.fr       */
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