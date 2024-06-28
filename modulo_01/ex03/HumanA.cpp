/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:35:18 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 12:55:43 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
	_name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::setName(std::string name) {
	_name = name;
}

void HumanA::attack() {
	std::cout << YELLOW << _name << " attacks with his " << _weapon.getType() << END << std::endl;
}
