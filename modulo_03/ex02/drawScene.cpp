/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawScene.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:42:48 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 18:39:20 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../colors.hpp"
#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>

void	waitAndClean(void)
{
	std::cout << UNDER_CYAN "\n Press enter to continue. " END << std::endl;
	std::string input("not empty");
	while (!input.empty())
		getline(std::cin, input);
	std::cout << "\033c";
}

void	drawMainScene(ClapTrap &clapOne, ClapTrap &clapTwo)
{
	std::cout << "\\                              /" << std::endl;
	std::cout << " \\   ~~,               ,~~    /" << std::endl;
	std::cout << " _\\_  (=>  _        _  <=)  _/_" << std::endl;
	std::cout << "  <}.==\"=./I\\      /I\\.=\"==.{>" << std::endl;
	std::cout << "    '-\\T/-\\I/      \\I/-\\T-'" << std::endl;
	std::cout << "      /_\\              /_\\" << std::endl;
	std::cout << "     // \\\\_           // \\\\_ " << std::endl;
	std::cout << "     I_   /           I_   /" << std::endl;
	std::cout << std::left;
	std::cout << std::setw(8) << "Name: " << std::setw(10) << clapOne.getName() << " | ";
	std::cout << std::setw(8) << "Name: " << std::setw(10) << clapTwo.getName() << std::endl;
	std::cout << std::setw(8) << "HP: " << std::setw(10) << clapOne.getHitPoint() << " | ";
	std::cout << std::setw(8) << "HP: " << std::setw(10) << clapTwo.getHitPoint() << std::endl;
	std::cout << std::setw(8) << "Energy: " << std::setw(10) << clapOne.getEnergyPoint() << " | ";
	std::cout << std::setw(8) << "Energy: " << std::setw(10) << clapTwo.getEnergyPoint() << std::endl;
  	waitAndClean();
}

void	drawAttackScene(void)
{
	std::cout << "                           /" << std::endl;
	std::cout << "  ~~,               ,~~   /" << std::endl;
	std::cout << "  (=>           _  <=)  _/_" << std::endl;
	std::cout << ".==\"=.<}-----  /I\\.=\"==.{>" << std::endl;
	std::cout << "'-\\T/-         \\I/-\\T-'" << std::endl;
	std::cout << "  /_\\              /_\\" << std::endl;
	std::cout << " // \\\\_           // \\\\_ " << std::endl;
	std::cout << " I_   /           I_   /" << std::endl;
  	waitAndClean();
}

void	drawDeathScene(void)
{
	std::cout << "  ~~,               ,~~" << std::endl;
	std::cout << "  (=>              <XX" << std::endl;
	std::cout << RED ".==\"=.<}-----    =======" END << std::endl;
	std::cout << "'-\\T/-            -\\T/-'" << std::endl;
	std::cout << "  /_\\              /_\\" << std::endl;
	std::cout << " // \\\\_           // \\\\_ " << std::endl;
	std::cout << " I_   /           I_   /" << std::endl;
  	waitAndClean();
}