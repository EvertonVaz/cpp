/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:25:03 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 18:51:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		int			hitPoint;
		int			energyPoint;
		int			attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &copy);
		void		attack(const std::string &target);
		void		attack(ClapTrap &target);
		void		beRepaired(ClapTrap &clap, unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		takeDamage(unsigned int amount);
		bool		isUnavailable(ClapTrap &clap);
		std::string	getName();
		int			getHitPoint();
		int			getEnergyPoint();
		int			getAttackDamage();
		void		showStatus();
		void		setAttackDamage(unsigned int amount);
		void		setHitPoint(unsigned int amount);
		void		setEnergyPoint(unsigned int amount);
};

void	waitAndClean(void);
void	drawMainScene(ClapTrap &clapOne, ClapTrap &clapTwo);
void	drawAttackScene();
void	drawDeathScene();

#endif