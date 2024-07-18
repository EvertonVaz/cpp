/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:25:17 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/17 15:25:45 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIRE_HPP
#define FIRE_HPP

#include "AMateria.hpp"

class Fire : public AMateria {
	public:
		Fire();
		Fire(Fire const &src);
		Fire &operator=(Fire const &rhs);
		~Fire();

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif