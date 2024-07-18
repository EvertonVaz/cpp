/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:38:38 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 15:46:04 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Cure.hpp"
#include "interfaces/ICharacter.hpp"
#include "../colors.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &src) : AMateria(src) {}

Cure &Cure::operator=(Cure const &rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout <<YELLOW ": * heals " END<< target.getName() <<YELLOW "’s wounds *" END<< std::endl;
}
