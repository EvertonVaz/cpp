/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:53:13 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 11:28:55 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "../colors.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout <<MAGENTA "Cat default constructor called" END<< std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	std::cout <<MAGENTA "Cat copy constructor called" END<< std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const &copy) {
	std::cout <<MAGENTA "Cat assignation operator called" END<< std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Cat::~Cat() {
	std::cout <<MAGENTA "Cat destructor called" END<< std::endl;
}

void Cat::makeSound() const {
	std::cout <<UNDER_MAGENTA "Cat sound: Miau Miau!" END<< std::endl;
}

std::string Cat::getType() const {
	return (this->_type);
}
