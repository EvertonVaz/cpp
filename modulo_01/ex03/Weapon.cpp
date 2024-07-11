/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:24:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/05 17:32:11 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) :
	_type(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}
