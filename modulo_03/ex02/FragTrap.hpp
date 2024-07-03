/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:23:28 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 18:33:38 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &copy);
		void		attack(ClapTrap &target);
		void		attack(const std::string &target);
		void		beRepaired(FragTrap &clap, unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		takeDamage(unsigned int amount);
		void		highFivesGuys(void);
		void		showStatus(void);
};

#endif