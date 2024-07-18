/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:52:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 11:59:31 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/AMateria.hpp"
#include "interfaces/ICharacter.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "Using materia on " << target.getName() << std::endl;
}

AMateria::~AMateria() {}