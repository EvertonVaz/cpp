/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:21:48 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 18:07:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "../colors.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << UNDER_CYAN "ScavTrap default constructor called" END << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << UNDER_CYAN "ScavTrap name constructor called" END << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	if (isUnavailable(*this))
		return;
	std::cout << UNDER_GREEN "ScavTrap " << this->name << " attack ";
	std::cout << target << ", causing " << this->attackDamage;
	std::cout << " points of damage!" END << std::endl;
	this->energyPoint--;
}

void	ScavTrap::attack(ClapTrap &target) {
	if (isUnavailable(*this))
		return ;
	if (isUnavailable(target))
		return ;
	this->attack(target.getName());
	target.takeDamage(this->attackDamage);
	target.setHitPoint(target.getHitPoint() - this->attackDamage);
	this->energyPoint--;
}

void	ScavTrap::guardGate(void)
{
	if (isUnavailable(*this))
		return;
	std::cout << YELLOW "ScavTrap " << this->name;
	std::cout << " has entered Gate keeper mode" END << std::endl;
	this->energyPoint--;
}

void	ScavTrap::showStatus() {
	std::cout << UNDER_CYAN "\nScavTrap " << this->name << " status:" END << std::endl;
	std::cout << "Hit Points: " << this->hitPoint << std::endl;
	std::cout << "Energy Points: " << this->energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}