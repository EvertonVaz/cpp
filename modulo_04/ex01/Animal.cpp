/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:46:46 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 14:09:19 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "../colors.hpp"

Animal::Animal() {
	_type = "Animal";
	std::cout <<YELLOW "Animal default constructor called" END<< std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout <<YELLOW "Animal type constructor called" END<< std::endl;
}

Animal::~Animal() {
	std::cout <<YELLOW "Animal destructor called" END<< std::endl;
}

Animal::Animal(Animal const &copy) {
	std::cout <<YELLOW "Animal copy constructor called" END<< std::endl;
	*this = copy;
}

Animal &Animal::operator=(Animal const &copy) {
	std::cout <<YELLOW "Animal assignation operator called" END<< std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void Animal::makeSound() const {
	std::cout <<UNDER_YELLOW "Animal makeSound called" END<< std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}

void Animal::setType(std::string type) {
	this->_type = type;
}
