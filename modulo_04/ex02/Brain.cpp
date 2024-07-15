/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:00:49 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/14 14:03:02 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "../colors.hpp"

Brain::Brain() {
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