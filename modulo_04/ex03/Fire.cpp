/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:26:24 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 15:27:32 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Fire.hpp"
#include "interfaces/ICharacter.hpp"
#include "../colors.hpp"

Fire::Fire() : AMateria("fire") {}

Fire::Fire(Fire const &src) : AMateria(src) {}

Fire &Fire::operator=(Fire const &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

Fire::~Fire() {}

AMateria *Fire::clone() const {
	return new Fire();
}

void Fire::use(ICharacter &target) {
	std::cout <<RED "* shoots an fire bolt at " END<< target.getName() <<RED " *" END<< std::endl;
}
