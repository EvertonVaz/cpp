/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:40:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/01 11:22:03 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#define RED "\033[41m"
#define YELLOW "\033[43m\033[30m"
#define END "\033[0m"

std::string	ft_input(std::string msg);
Contact		createContact(void);

class	PhoneBook {

	private:
		Contact		_contacts[8];
		int			currentContactIndex;
		int			contactsCount;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(const Contact& contact);
		void	searchContact(void) const;
		void	displayContact(void) const;
};

#endif