/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:53:13 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/18 10:09:42 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "../colors.hpp"

Dog::Dog() : AAnimal("Dog") {
    std::cout <<CYAN "Dog default constructor called" END<< std::endl;
    this->_brain = new Brain();
}

Dog::Dog(Dog const &copy) : AAnimal(copy) {
    std::cout <<CYAN "Dog copy constructor called" END<< std::endl;
    this->_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(Dog const &copy) {
    std::cout <<CYAN "Dog assignation operator called" END<< std::endl;
    if (this != &copy) {
        AAnimal::operator=(copy);
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

std::string *Dog::getBrain() const {
    return this->_brain->getIdea();
}