/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:13:16 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/04 11:15:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "../colors.hpp"
#include <cstdlib>

std::string	gameMenu() {
	std::string	command;
	std::cout << "Choose your action:" << std::endl;
	std::cout << "1. ATTACK" << std::endl;
	std::cout << "2. REPAIR" << std::endl;
	std::cout << "3. GUARD GATE" << std::endl;
	std::cout << "4. HIGH FIVE" << std::endl;
	std::cout << "5. WHO AMI" << std::endl;
	std::cout << "6. EXIT" << std::endl;
	std::cout << "Enter command: ";
	std::getline(std::cin, command);
	std::cout << "\033c";
	return (command);
}

void	doAttack(FragTrap &clapOne, DiamondTrap &clapTwo) {
	clapOne.attack(clapTwo);
	drawAttackScene();
	clapTwo.attack(clapOne);
	drawAttackScene();
}

int	main(void) {
	srand(static_cast<unsigned int>(time(0)));
	std::string	command;

	ClapTrap clap;
	FragTrap frag("Bob Sponge");
	ScavTrap scav("Patrick Star");
	DiamondTrap diamond("Squidward Tentacles");
	std::cout << "Welcome to ClapTrap game!" << std::endl;
	while (!frag.isUnavailable(frag) && !diamond.isUnavailable(diamond)) {
		drawMainScene(frag, diamond);
		command = gameMenu();
		if (command == "1" || command == "ATTACK") {
			doAttack(frag, diamond);
		}
		else if (command == "2" || command == "REPAIR") {
			frag.beRepaired(frag, rand() % 10);
			diamond.beRepaired(diamond, rand() % 10);
		}
		else if (command == "3" || command == "GUARD GATE") {
			diamond.guardGate();
		}
		else if (command == "4" || command == "HIGH FIVE") {
			diamond.highFivesGuys();
		}
		else if (command == "5" || command == "WHO AMI") {
			diamond.whoAmI();
		}
		else if (command == "6" || command == "EXIT")
			break;
		else
			std::cout << RED "Invalid command" END << std::endl;
	}
	if (frag.isUnavailable(frag))
		drawDeathScene();
	else if (diamond.isUnavailable(diamond))
		drawDeathScene();
	frag.showStatus();
	diamond.showStatus();
	std::cout << BOLD_RED "\nGame Over!\n" END << std::endl;
	return 0;
}