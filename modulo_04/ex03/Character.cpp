/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:57:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 18:04:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Character.hpp"
#include "classes/AMateria.hpp"

Character::Character() : _name("Default"), _unequipped() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name), _unequipped() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &src) :
		_name(src._name), _unequipped(src._unequipped) {
	for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character &Character::operator=(Character const &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	_unequipped = rhs._unequipped;
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	_unequipped.clear();
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	if (!m) return;

    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == m) {
            std::cout << "Item already equipped!" << std::endl;
            return;
        }
    }
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			m = NULL;
			return ;
		}
	}
	_unequipped.add(m);
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_unequipped.add(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		std::cout << this->getName() << " uses ";
		_inventory[idx]->use(target);
	}
}
