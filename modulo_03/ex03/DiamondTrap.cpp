/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:50:10 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/16 12:26:06 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "../colors.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name("Default")
{
	std::cout << UNDER_YELLOW "DiamondTrap default constructor called" END << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << UNDER_YELLOW "DiamondTrap name constructor called" END << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), name(copy.name)
{
	std::cout << UNDER_YELLOW "DiamondTrap copy constructor called" END << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << UNDER_YELLOW "DiamondTrap destructor called" END << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << YELLOW "DiamondTrap name: " << this->name << ", ClapTrap name: " << this->ClapTrap::name << END << std::endl;
}

void	DiamondTrap::attack(ClapTrap &target)
{
	if (isUnavailable(*this))
		return ;
	if (isUnavailable(target))
		return ;
	ScavTrap::attack(target.getName());
	target.takeDamage(this->attackDamage);
	target.setHitPoint(target.getHitPoint() - this->attackDamage);
	this->energyPoint--;
}

void	DiamondTrap::showStatus(void)
{
	std::cout << BOLD_YELLOW "DiamondTrap " << this->name << " status:" END << std::endl;
	std::cout << "Hit points: " << this->hitPoint << std::endl;
	std::cout << "Energy points: " << this->energyPoint << std::endl;
	std::cout << "Attack damage: " << this->attackDamage << std::endl;
}
