/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:44:03 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/05 17:25:26 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	N;

	N = 9;
	Zombie* horde = zombieHorde(N, "Horde Zombie");
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}