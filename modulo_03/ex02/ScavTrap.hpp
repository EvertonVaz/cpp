/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:13:26 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 18:33:42 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &copy);
		void		attack(ClapTrap &target);
		void		attack(const std::string &target);
		void		beRepaired(ScavTrap &clap, unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		takeDamage(unsigned int amount);
		void		guardGate(void);
		void		showStatus(void);
};

#endif
