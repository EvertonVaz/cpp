/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:31:24 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 18:45:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include "../colors.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << UNDER_BLUE "FragTrap default constructor called" END << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << UNDER_BLUE "FragTrap name constructor called" END << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void	FragTrap::attack(const std::string &target) {
	if (isUnavailable(*this))
		return;
	std::cout << UNDER_CYAN "FragTrap " << this->name << " attack ";
	std::cout << target << ", causing " << this->attackDamage;
	std::cout << " points of damage!" END << std::endl;
}

void	FragTrap::attack(ClapTrap &target) {
	if (isUnavailable(*this))
		return ;
	if (isUnavailable(target))
		return ;
	this->attack(target.getName());
	target.takeDamage(this->attackDamage);
	target.setHitPoint(target.getHitPoint() - this->attackDamage);
	this->energyPoint--;
}

void	FragTrap::beRepaired(unsigned int amount) {
	std::cout << CYAN "FragTrap " << this->name << " be repaired ";
	std::cout << amount << " points of health!" END << std::endl;
	this->hitPoint += amount;
}

void	FragTrap::beRepaired(FragTrap &clap, unsigned int amount) {
	if (isUnavailable(clap))
		return ;
	beRepaired(amount);
	clap.hitPoint += amount;
	clap.energyPoint--;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (isUnavailable(*this))
		return;
	std::cout << MAGENTA "FragTrap " << this->name << " take ";
	std::cout << amount << " points of damage!" END << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << UNDER_YELLOW "FragTrap " << this->name << " high fives guys!" END << std::endl;
}

void	FragTrap::showStatus(void) {
	std::cout << UNDER_CYAN "\nScavTrap " << this->name << " status:" END << std::endl;
	std::cout << "Hit Points: " << this->hitPoint << std::endl;
	std::cout << "Energy Points: " << this->energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}