/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:42:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/04 10:49:28 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();

		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap	&operator=(const DiamondTrap &copy);
		void	whoAmI();
		void	attack(const std::string &target);
		void	attack(ClapTrap &target);
		void	beRepaired(DiamondTrap &clap, unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	takeDamage(unsigned int amount);
		void	showStatus(void);
};

#endif