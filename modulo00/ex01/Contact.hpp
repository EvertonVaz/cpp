/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:41:28 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/27 08:47:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;


	public:
		void		setFirstName(const std::string& firstName);
		void		setLastName(const std::string& lastName);
		void		setNickname(const std::string& nickname);
		void		setPhoneNumber(const std::string& phoneNumber);
		void		setDarkestSecret(const std::string& darkestSecret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
};

#endif