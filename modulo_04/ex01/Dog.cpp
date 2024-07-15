/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:53:13 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 15:42:05 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "../colors.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout <<CYAN "Dog default constructor called" END<< std::endl;
    this->_brain = new Brain();
}

Dog::Dog(Dog const &copy) : Animal(copy) {
    std::cout <<CYAN "Dog copy constructor called" END<< std::endl;
    this->_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(Dog const &copy) {
    std::cout <<CYAN "Dog assignation operator called" END<< std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);
    }
    return (*this);
}

Dog::~Dog() {
    std::cout <<CYAN "Dog destructor called" END<< std::endl;
    delete this->_brain;
}

void Dog::makeSound() const {
    std::cout <<CYAN "Dog sound: Woof Woof!" END<< std::endl;
}

std::string Dog::getType() const {
	return (this->_type);
}
