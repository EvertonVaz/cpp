/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:04:55 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/21 15:53:19 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string	Contact::getLastName(void) const {
	return this->_lastName;
}

std::string	Contact::getNickname(void) const {
	return this->_nickname;
}

std::string	Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

void Contact::setFirstName(const std::string& firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
