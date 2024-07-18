/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:53:13 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/16 15:14:45 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "../colors.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout <<CYAN "Dog default constructor called" END<< std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy) {
	std::cout <<CYAN "Dog copy constructor called" END<< std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const &copy) {
	std::cout <<CYAN "Dog assignation operator called" END<< std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Dog::~Dog() {
	std::cout <<CYAN "Dog destructor called" END<< std::endl;
}

void Dog::makeSound() const {
	std::cout <<UNDER_CYAN "Dog sound: Woof Woof!" END<< std::endl;
}

