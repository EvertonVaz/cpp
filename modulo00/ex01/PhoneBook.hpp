/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:40:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/21 15:10:12 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {

	private:
		Contact		_contacts[8];
		int			currentContactIndex;
		int			contactsCount;

	public:
		PhoneBook();
		void	addContact(const Contact& contact);
		void	searchContact(void) const;
		void	displayContact(int index) const;
};

#endif