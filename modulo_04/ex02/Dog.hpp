/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:52:35 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/18 10:08:38 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(Dog const &copy);
		Dog &operator=(Dog const &copy);
		virtual ~Dog();
		void makeSound() const;
		std::string getType() const;
		std::string *getBrain() const;
};

#endif