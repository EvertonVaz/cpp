/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:52:35 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 14:03:45 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
		
	public:
		Dog();
		Dog(Dog const &copy);
		Dog &operator=(Dog const &copy);
		virtual ~Dog();
		void makeSound() const;
		std::string getType() const;
};

#endif