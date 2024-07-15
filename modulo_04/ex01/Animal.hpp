/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:42:29 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 14:09:09 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &copy);
		Animal &operator=(Animal const &copy);
		virtual ~Animal();
		virtual void makeSound() const;
		virtual std::string getType() const;
		virtual void setType(std::string type);
};

#endif