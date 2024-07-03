/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:30:08 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 15:02:31 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "../colors.hpp"

ClapTrap::ClapTrap() :
	name("ClapTrap"), hitPoint(10), energyPoint(10), attackDamage(0) {
	std::cout << UNDER_WHITE "ClapTrap default constructor called" END << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	name(name), hitPoint(10), energyPoint(10), attackDamage(0) {
	std::cout << UNDER_WHITE "ClapTrap constructor called" END << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << BOLD_YELLOW  "ClapTrap copy constructor called" END << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap() {
	std::cout << UNDER_RED "ClapTrap destructor called" END << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << BOLD_YELLOW "ClapTrap assignation operator called" END << std::endl;
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	std::cout << GREEN "ClapTrap " << this->name << " attack ";
	std::cout << target << ", causing " << this->attackDamage;
	std::cout << " points of damage!" END << std::endl;
}

void	ClapTrap::attack(ClapTrap &target) {
	if (!clapTrapIsAlive(*this))
		return ;
	if (!clapTrapIsAlive((ClapTrap &)target))
		return ;
	attack(target.name);
	target.takeDamage(this->attackDamage);
	target.hitPoint -= this->attackDamage;
	clapTrapIsAlive(target);
	this->energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << MAGENTA "ClapTrap " << this->name << " take ";
	std::cout << amount << " points of damage!" END << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << CYAN "ClapTrap " << this->name << " be repaired ";
	std::cout << amount << " points of health!" END << std::endl;
}

void	ClapTrap::beRepaired(ClapTrap &clap, unsigned int amount) {
	if (!clapTrapIsAlive(clap))
		return ;
	beRepaired(amount);
	clap.hitPoint += amount;
	clap.energyPoint--;
}
