/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:46:08 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 16:40:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void ){
	std::cout << "Debug: ";
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << "I really do!" << std::endl;
}

void	Harl::info( void ){
	std::cout << GREEN << "Info: ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put";
	std::cout << " enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << END << std::endl;
}

void	Harl::warning( void ){
	std::cout << YELLOW << "Warning: ";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for";
	std::cout << " years whereas you started working here since last month.";
	std::cout << END << std::endl;
}

void	Harl::error( void ){
	std::cout << RED << "Error: ";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << END << std::endl;
}

void	Harl::complain(std::string level){
	void	(Harl::*comments[])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	std::string	levels[] = {
		"debug", "info", "warning", "error"
	};

	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			(this->*comments[i])();
			return ;
		}
	}
	std::cerr << MAGENTA "Invalid level" END <<  std::endl;
}