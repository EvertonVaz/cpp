/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:13:16 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 19:02:25 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "../colors.hpp"
#include <cstdlib>

std::string	gameMenu() {
	std::string	command;
	std::cout << "Choose your action:" << std::endl;
	std::cout << "1. ATTACK" << std::endl;
	std::cout << "2. REPAIR" << std::endl;
	std::cout << "3. GUARD GATE" << std::endl;
	std::cout << "4. HIGH FIVE" << std::endl;
	std::cout << "5. EXIT" << std::endl;
	std::cout << "Enter command: ";
	std::getline(std::cin, command);
	std::cout << "\033c";
	return (command);
}

void	doAttack(FragTrap &clapOne, ScavTrap &clapTwo) {
	clapOne.attack(clapTwo);
	drawAttackScene();
	clapTwo.attack(clapOne);
	drawAttackScene();
}

int	main(void) {
	srand(static_cast<unsigned int>(time(0)));
	std::string	command;

	FragTrap clap("Bob Sponge");
	ScavTrap clap2("Patrick Star");
	std::cout << "Welcome to ClapTrap game!" << std::endl;
	while (!clap.isUnavailable(clap) && !clap2.isUnavailable(clap2)) {
		drawMainScene(clap, clap2);
		command = gameMenu();
		if (command == "1" || command == "ATTACK") {
			doAttack(clap, clap2);
		}
		else if (command == "2" || command == "REPAIR") {
			clap.beRepaired(clap, rand() % 10);
			clap2.beRepaired(clap2, rand() % 10);
		}
		else if (command == "3" || command == "GUARD GATE") {
			clap2.guardGate();
		}
		else if (command == "4" || command == "HIGH FIVE") {
			clap.highFivesGuys();
		}
		else if (command == "5" || command == "EXIT")
			break;
		else
			std::cout << RED "Invalid command" END << std::endl;
	}
	if (clap.isUnavailable(clap))
		drawDeathScene();
	else if (clap2.isUnavailable(clap2))
		drawDeathScene();
	clap.showStatus();
	clap2.showStatus();
	std::cout << BOLD_RED "\nGame Over!\n" END << std::endl;
	return 0;
}