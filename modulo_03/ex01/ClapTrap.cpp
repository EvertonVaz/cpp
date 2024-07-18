/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:30:08 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/16 14:46:00 by egeraldo         ###   ########.fr       */
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
	std::cout << UNDER_WHITE "ClapTrap " << this->name << " attack ";
	std::cout << target << ", causing " << this->attackDamage;
	std::cout << " points of damage!" END << std::endl;
}

void	ClapTrap::attack(ClapTrap &target) {
	if (isUnavailable(*this))
		return ;
	if (isUnavailable(target))
		return ;
	attack(target.name);
	target.takeDamage(this->attackDamage);
	target.hitPoint -= this->attackDamage;
	this->energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << UNDER_WHITE << this->name << " take ";
	std::cout << amount << " points of damage!" END << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << UNDER_WHITE << this->name << " be repaired ";
	std::cout << amount << " points of health!" END << std::endl;
}

void	ClapTrap::beRepaired(ClapTrap &clap, unsigned int amount) {
	if (isUnavailable(clap))
		return ;
	clap.hitPoint += amount;
	clap.energyPoint--;
	beRepaired(amount);
}

bool	ClapTrap::isUnavailable(ClapTrap &clap) {
	if (clap.energyPoint <= 0) {
		std::cout << UNDER_YELLOW << clap.name;
		std::cout << " is out of energy!" END << std::endl;
		return true;
	}
	if (clap.hitPoint <= 0) {
		std::cout << RED << clap.name;
		std::cout << " is dead!" END << std::endl;
		clap.hitPoint = 0;
		return true;
	}
	return false;
}

int		ClapTrap::getHitPoint(void) {
	return this->hitPoint;
}

int		ClapTrap::getEnergyPoint(void) {
	return this->energyPoint;
}

int		ClapTrap::getAttackDamage(void) {
	return this->attackDamage;
}

std::string	ClapTrap::getName(void) {
	return this->name;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->attackDamage = amount;
}

void	ClapTrap::setHitPoint(unsigned int amount) {
	this->hitPoint = amount;
}

void	ClapTrap::showStatus(void) {
	std::cout << UNDER_WHITE "\nClapTrap " << this->name << " status:" END << std::endl;
	std::cout << "Hit Points: " << this->hitPoint << std::endl;
	std::cout << "Energy Points: " << this->energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}