/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:40:23 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:27 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../interfaces/ICharacter.hpp"
#include "LinkedList.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *_inventory[4];
		LinkedList _unequipped;

	public:
		Character();
		Character(std::string const &name);
		Character(Character const &src);
		Character &operator=(Character const &rhs);
		~Character();

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif