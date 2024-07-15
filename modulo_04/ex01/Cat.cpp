/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:53:13 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 15:43:13 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "../colors.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout <<MAGENTA "Cat default constructor called" END<< std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	std::cout <<MAGENTA "Cat copy constructor called" END<< std::endl;
	this->_brain = new Brain(*copy._brain);
}

Cat &Cat::operator=(Cat const &copy) {
	std::cout <<MAGENTA "Cat assignation operator called" END<< std::endl;
	if (this != &copy) {
        Animal::operator=(copy);
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    return (*this);
}

Cat::~Cat() {
	std::cout <<MAGENTA "Cat destructor called" END<< std::endl;
	delete this->_brain;
}

void Cat::makeSound() const {
	std::cout <<UNDER_MAGENTA "Cat sound: Meow Meow!" END<< std::endl;
}

std::string Cat::getType() const {
	return (this->_type);
}
