/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:40:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/26 14:31:36 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include "Contact.hpp"

#define RED "\033[41m"
#define YELLOW "\033[43m"
#define END "\033[0m"

class	PhoneBook {

	private:
		Contact		_contacts[8];
		int			currentContactIndex;
		int			contactsCount;

	public:
		PhoneBook();
		void	addContact(const Contact& contact);
		void	searchContact(void) const;
		void	displayContact(void) const;
};

#endif