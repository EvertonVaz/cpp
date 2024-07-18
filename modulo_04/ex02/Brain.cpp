/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:00:49 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/18 09:59:22 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "../colors.hpp"

Brain::Brain() {
	std::string	idea = "I am a idea";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
	std::cout <<GREEN "Brain default constructor called" END<< std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout <<GREEN "Brain copy constructor called" END<< std::endl;
	*this = copy;
}

Brain &Brain::operator=(Brain const &copy) {
	std::cout <<GREEN "Brain assignation operator called" END<< std::endl;
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout <<GREEN "Brain destructor called" END<< std::endl;
}

std::string *Brain::getIdea() const {
	return ((std::string *)this->_ideas);
}
