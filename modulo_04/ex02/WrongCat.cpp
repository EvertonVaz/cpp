/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:42:06 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 13:44:13 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "../colors.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout <<BOLD_RED "WrongCat type constructor called" END<< std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy) {
	std::cout <<BOLD_RED "WrongCat copy constructor called" END<< std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &copy) {
	std::cout <<BOLD_RED "WrongCat assignation operator called" END<< std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout <<BOLD_RED "WrongCat destructor called" END<< std::endl;
}

void WrongCat::makeSound() const {
	std::cout <<UNDER_RED "WrongCat sound: Meow Meow!" END<< std::endl;
}

std::string WrongCat::getType() const {
	return (this->_type);
}