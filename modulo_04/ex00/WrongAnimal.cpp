/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:35:51 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 13:39:57 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "../colors.hpp"

WrongAnimal::WrongAnimal() {
	_type = "WrongAnimal";
	std::cout <<RED "WrongAnimal default constructor called" END<< std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout <<RED "WrongAnimal type constructor called" END<< std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout <<RED "WrongAnimal destructor called" END<< std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
	std::cout <<RED "WrongAnimal copy constructor called" END<< std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy) {
	std::cout <<RED "WrongAnimal assignation operator called" END<< std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout <<UNDER_RED "WrongAnimal makeSound called" END<< std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}

