/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:39:40 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/05 17:21:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <sstream>

Zombie*	zombieHorde(int N, std::string name) {
	std::stringstream ss;
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		ss << i;
		horde[i].setName(name + ss.str());
		ss.clear();
	}
	return (horde);
}