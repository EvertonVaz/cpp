/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:54:51 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 17:06:32 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "../interfaces/IMateriaSource.hpp"
#include "LinkedList.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_inventory[4];
		LinkedList _unequipped;

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		MateriaSource &operator=(MateriaSource const &rhs);
		~MateriaSource();

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif