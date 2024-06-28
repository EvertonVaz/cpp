/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:01:06 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 12:53:53 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	_name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (_weapon)
		std::cout << OCEAN << _name << " attacks with his " << _weapon->getType() << END << std::endl;
	else
		std::cout << OCEAN << _name << " has no weapon to attack with" << END << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::setName(std::string name) {
	_name = name;
}
