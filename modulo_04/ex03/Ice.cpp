/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:27:25 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 15:43:34 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Ice.hpp"
#include "interfaces/ICharacter.hpp"
#include "../colors.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &src) : AMateria(src) {}

Ice &Ice::operator=(Ice const &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout <<CYAN "* shoots an ice bolt at " END<< target.getName() <<CYAN " *" END<< std::endl;
}
