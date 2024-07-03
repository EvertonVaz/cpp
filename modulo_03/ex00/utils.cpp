/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:32:27 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 15:02:56 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "../colors.hpp"

bool	ClapTrap::clapTrapIsAlive(ClapTrap &clap) {
	if (clap.hitPoint <= 0) {
		std::cout << RED "ClapTrap " << clap.name << " is dead!" END << std::endl;
		clap.hitPoint = 0;
		return false;
	}
	if (clap.getEnergyPoint() <= 0) {
		std::cout << RED "ClapTrap " << clap.name << " is out of energy!" END << std::endl;
		return false;
	}
	return true;
}

int		ClapTrap::getHitPoint() {
	return this->hitPoint;
}

int		ClapTrap::getEnergyPoint() {
	return this->energyPoint;
}

int		ClapTrap::getAttackDamage() {
	return this->attackDamage;
}

std::string	ClapTrap::getName() {
	return this->name;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->attackDamage = amount;
}

void	ClapTrap::showStatus() {
	std::cout << UNDER_CYAN "ClapTrap " << this->name << " status:" END << std::endl;
	std::cout << "Hit Points: " << this->hitPoint << std::endl;
	std::cout << "Energy Points: " << this->energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}