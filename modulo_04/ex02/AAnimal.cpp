/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:46:46 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 15:35:42 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "../colors.hpp"

AAnimal::AAnimal() {
	_type = "AAnimal";
	std::cout <<YELLOW "AAnimal default constructor called" END<< std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout <<YELLOW "AAnimal type constructor called" END<< std::endl;
}

AAnimal::~AAnimal() {
	std::cout <<YELLOW "AAnimal destructor called" END<< std::endl;
}

AAnimal::AAnimal(AAnimal const &copy) {
	std::cout <<YELLOW "AAnimal copy constructor called" END<< std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(AAnimal const &copy) {
	std::cout <<YELLOW "AAnimal assignation operator called" END<< std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

std::string AAnimal::getType() const {
	return (this->_type);
}

void AAnimal::setType(std::string type) {
	this->_type = type;
}
