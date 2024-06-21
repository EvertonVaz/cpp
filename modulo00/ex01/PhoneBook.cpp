/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:08:47 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/21 15:12:21 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentContactIndex(0), contactsCount(0) {};

void	PhoneBook::addContact(const Contact& contact) {
	_contacts[currentContactIndex] = contact;
    currentContactIndex = (currentContactIndex + 1) % 8;
    if (contactsCount < 8)
		contactsCount++;
}