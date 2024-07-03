/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:13:16 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 15:07:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "../colors.hpp"
#include <cstdlib>

std::string	gameMenu() {
	std::string	command;
	std::cout << "Choose your action:" << std::endl;
	std::cout << "1. ATTACK" << std::endl;
	std::cout << "2. REPAIR" << std::endl;
	std::cout << "3. EXIT" << std::endl;
	std::cout << "Enter command: ";
	std::getline(std::cin, command);
	return (command);
}

void	isAlive(ClapTrap &clapOne, ClapTrap &clapTwo) {
	if (clapOne.getHitPoint() > 0 && clapTwo.getHitPoint() > 0) {
		clapOne.attack(clapTwo);
		drawAttackScene();
	}
	else
		drawDeathScene();
}

int	main(void) {
	srand(static_cast<unsigned int>(time(0)));
	std::string	command;

	ClapTrap clap("Bob Sponge");
	ClapTrap clap2("Patrick Star");
	std::cout << "Welcome to ClapTrap game!" << std::endl;
	while (clap.clapTrapIsAlive(clap) && clap2.clapTrapIsAlive(clap2)) {
		drawMainScene(clap, clap2);
		command = gameMenu();
		if (command == "1" || command == "ATTACK") {
			clap.setAttackDamage(rand() % 10);
			clap2.setAttackDamage(rand() % 10);
			isAlive(clap2, clap);
			isAlive(clap, clap2);
		}
		else if (command == "2" || command == "REPAIR") {
			clap.beRepaired(clap, rand() % 10);
			clap2.beRepaired(clap2, rand() % 10);
		}
		else if (command == "3" || command == "EXIT")
			break;
		else
			std::cout << RED "Invalid command" END << std::endl;
	}
	clap.showStatus();
	clap2.showStatus();
	std::cout << BOLD_RED "Game Over!" END << std::endl;
	return 0;
}