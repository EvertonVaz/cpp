/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:12:19 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 12:54:32 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

#define YELLOW	"\033[33m"
#define OCEAN	"\033[36m"
#define END		"\033[0m"

class Weapon {
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string const &getType();
		void setType(std::string type);
};

#endif